#updated for S23 by Mason Tumminelli
#original code by Connor Rickermann
#changelog: reformatted and reorganized code for better readability. Updated to support autograding. Removed unnecessary code & condensed.
from Crypto.PublicKey import RSA
from Crypto.Hash import SHA256
from Crypto.Signature import PKCS1_v1_5
import os
import random
import shutil
import secrets
import string
import json

import utils.GenPTandKey4 as q4
import utils.GenPTandKey5 as q5

def generateFakeExecutables(): #function that handles setup for Q1, Q2 and Q3
    os.mkdir("Q1files")
    os.mkdir("Q2files")
    os.mkdir("Q3files")
    DIRS = [1,2,3]
    NO_PROGS = [15,40,15]
    parent_dir = os.getcwd()
    wl = open('utils/wordlist.txt', 'r').read().split()
    for qn in DIRS:
        dirnme = os.path.join(parent_dir, "Q"+str(qn)+"files")
        for i in range(NO_PROGS[qn-1]):
            prgnme = os.path.join(dirnme, str(random.choice(wl).strip())+".exe")
            with open(prgnme, 'wb') as prg:
                prg.write(secrets.token_bytes(random.randint(512,8192)))

def hashFile(d): #simple hash program by digesting entire file, takes dir as input
    opts = os.listdir(d)
    f = (random.choice(opts))
    f_direct = os.path.join(d, f)
    f_content = open(f_direct, "rb")
    hash_object = SHA256.new(f_content.read())
    dig = hash_object.hexdigest()
    return f, dig

def generateSignature(key, data, sig_f): # Generates signatures
    h = SHA256.new(data)
    rsa = RSA.importKey(key)
    signer = PKCS1_v1_5.new(rsa)
    signature = signer.sign(h)
    with open('Q3files/'+sig_f, 'wb') as f: f.write(signature)
    f.close()

def labGen(): #main labgen
    studentSolution = {} #for autograding
    generateFakeExecutables() #prepare setup

    #[===Q1 and 2===]
    for i in range(1,3):
        dirname = os.getcwd()
        dir1 = os.path.join(dirname, f"Q{i}files")
        hash = hashFile(dir1)
        with open(f"Q{i}hash.txt", 'w') as f: 
            f.write(hash[1]+"\n")
        f.close()
        studentSolution[f"Q{i}"] = hash[0] #the name of the matching file

    #[=== Q3 ===]
    key1 = RSA.generate(2048) # Generate keys
    private_key = key1.export_key()
    public_key = key1.publickey().export_key()
    file_out = open("Q3pk.pem", "wb")
    file_out.write(public_key)
    file_out.close()

    key2 = RSA.generate(2048)
    false_private = key2.export_key()
    files = os.listdir('Q3files/')
    random.shuffle(files)
    flag = False
    for file in files:
        if '.exe' not in file or '.sign' in file: continue
        if flag == False: #select one file
            key = private_key
            studentSolution[f"Q3"] = file
            flag=True
        else: key = false_private
        with open('Q3files/'+ file, 'rb') as f: data = f.read()
        generateSignature(key, data, file +'.sign')

    #[=== Pre-Q4 and Q5 setup ===] #does admin work
    os.mkdir("Q4files")
    os.mkdir("Q5files")
    shutil.copy("utils/wordlist.txt", "wordlist.txt")
    shutil.copy("utils/GenPTandKey4.py", "Q4files/GenPTandKey4.py")
    shutil.copy("utils/R0_4.py", "Q4files/R0.py")
    shutil.copy("utils/GenPTandKey5.py", "Q5files/GenPTandKey5.py")
    shutil.copy("utils/R0_5.py", "Q5files/R0.py")

    #[=== Q4 ===]
    os.chdir("Q4files")
    studentSolution[f"Q4"] = q4.run().decode("utf-8") #convert bytes to string
    os.system("python3 R4.py")
    os.remove("GenPTandKey4.py")
    os.remove("R0.py")
    os.remove("plaintext.txt")

    #[=== Q5 ===]
    os.chdir("../Q5files")
    studentSolution[f"Q5"] = q5.run().decode("utf-8") #convert bytes to string
    os.system("python3 R5.py")
    os.remove("GenPTandKey5.py")
    os.remove("R0.py")
    os.remove("p2.txt")
    os.chdir("..")
    os.remove("wordlist.txt")

    #[=== Q6 ===]
    os.mkdir("Q6files")
    studentSolution["Q6"] = ''.join(random.choices(string.ascii_uppercase + string.digits, k=6))

    #[=== Write Solutions ===]
    with open('Solutions.json', "w") as f:
        json.dump(studentSolution,f)
    f.close()
    os.mkdir("LabGen")
    shutil.move("Lab3Gen.py", "LabGen/Lab3Gen.py")
    shutil.move("utils", "LabGen/utils")

    #[=== Give/Fix Permissions ===]
    os.chdir("..")
    os.system("chown -R cse:cse Lab3")

    print("Success!")

labGen()
