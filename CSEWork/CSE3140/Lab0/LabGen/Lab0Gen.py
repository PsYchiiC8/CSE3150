#changelog: changed from .txt to dictionary in .json for solutions file

# Generate files for Lab0 (all in directory Lab0)
# file whose name is of the form Q3Ax where x is random btw 1 and 99999, which contains y times the character 'X', y is random between 1 and 999.
import random
import os
import sys 
import json
import shutil

#===|[ Generate ]|===#
def Gen():
    studentSolution = {}

    # if len(sys.argv)==3:
    #     section=sys.argv[1]
    #     group=sys.argv[2]   # run with section number and group number 
    # else:
    #     group='?'           # or without parameters and then section, group = '?'
    #     section='?'

    #solfile=open('Solutions.json',mode='w+')   # can append to same file

    # Q3
    x=random.choice(range(99999))
    q3file=open("Q3."+str(x),mode='w')
    y=random.choice(range(999))
    for i in range(y):
        q3file.write('X')
    q3file.close()

    os.system(f"chown cse:cse Q3.{x}")
    os.chmod(f"Q3.{x}", 0o755)

    studentSolution["Q1"] = ""
    studentSolution["Q2"] = ""
    studentSolution["Q3A"] = f"{'Q3.'+str(x)}"
    studentSolution["Q3B"] = str(y)

    # Q4
    # create file Passwords, a simple `cleartext’ passwords file, where each line contains a user-id followed by a comma and a password.
    # question is to find the password for userid U44444.

    solpw=str(random.choice(range(99999)))
    studentSolution["Q4"] = f"{'P'+solpw}"

    pwfls=['U44444,P'+solpw+'\n']  # list of pw file lines

    for i in range(999):
        l=list(range(99999))
        l.remove(44444)
        u=str(random.choice(l))
     #   print('U'+u)
        if u[0] != '6': u += 'Y'
        pwfls.append('U'+u+',P'+str(random.choice(range(99999)))+'\n')

    # Q5
    # create a file named "Q5" whose contents is random number
    q5file=open("Q5",mode='w')
    solpw=str(random.choice(range(99999)))
    q5file.write('V'+solpw)
    q5file.close()

    studentSolution["Q5"] = f"{'V'+solpw}"

    os.system("chown cse:cse Q5")
    os.chmod("Q5", 0o000)

    # Q6
    # add one pair of the form U6xxxxxY,Pxxxxx
    solpw=str(random.choice(range(99999)))
    username = 'U6'+str(random.choice(range(99999)))+'Y'
    pwfls.append(username+',P'+solpw+'\n')

    studentSolution["Q6"] = username

    # finally add 50 pairs of the form U6xxxxxN,Pxxxxx
    for i in range (50):
        pwfls.append('U6'+str(random.choice(range(99999)))+'N,P'+str(random.choice(range(99999)))+'\n')

    # shuffle to get random locations             
    random.shuffle(pwfls)

    pwfile=open("Passwords.txt",mode='w')
    for l in pwfls:
         pwfile.write(l)
    pwfile.close()

    os.system("chown cse:cse Passwords.txt")
    os.chmod("Passwords.txt", 0o755)

    # Q7
    # write a py file that prints a string consisting of the letter S followed by 15 digits. Save this also in solutions.
    q7='S'+str(random.choice(range(9999999)))
    q7+=str(random.choice(range(9999999)))
    q7+=str(random.choice(range(9999999)))

    studentSolution["Q7"] = q7

    q7file=open("Q7.py",mode='w')
    q7file.write("print('"+q7+"')\n")
    q7file.close()

    #write solutions to JSON file
    with open('Solutions.json', "w") as f:
        json.dump(studentSolution,f)
    f.close()

    os.system("chown cse:cse Q7.py")
    os.chmod("Q7.py", 0o000)

    os.system("chown cse:cse Solutions.json")
    os.chmod("Solutions.json", 0o755)

    # Ronald Maule 1/17/2023
    # Create sub directories
    os.mkdir("Solutions")
    os.system("chown cse:cse Solutions")
    os.chmod("Solutions", 0o755)

    os.mkdir("LabGen")
    os.system("chown cse:cse LabGen")
    os.chmod("LabGen", 0o755)

    shutil.move("Lab0Gen.py", "LabGen/")

    print('Done!')
    

#===|[ Runtime ]|===#
if __name__ == "__main__":
    Gen()
