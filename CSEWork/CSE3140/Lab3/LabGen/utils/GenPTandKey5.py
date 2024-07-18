import random
import os

def run():
    def genPT():
        specialchar = ["!", "$", "%", "&", "@"]
        numbers = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
        output_file = 'p2.txt'
        lines = open('../wordlist.txt').read().splitlines()
        string1 = random.choice(lines).strip() + random.choice(numbers) + random.choice(numbers) + random.choice(specialchar)
        string1 = string1.encode('utf-8')
        file_out = open(output_file, "wb") 
        file_out.write(string1) # Write the varying length ciphertext to the file (this is the encrypted data)
        file_out.write(b'\n') # Write the varying length ciphertext to the file (this is the encrypted data)
        file_out.close()
        return string1

    output_file2 = '.key.txt'
    def generateVar():
        key = os.urandom(16)
        return key

    size = [64,128,256,512,1024,2048,4096]

    q5_ans = genPT()
    #key = generateVar()
    #print(key)
    search_text = b'tobereplaced'
    replace_text = random.choice(size)
    #print(replace_text)
    with open(r'R0.py', 'r') as file:
        data = file.read()
        data = data.replace(str(search_text), str(replace_text))
    with open(r'R5.py', 'w') as file:
        file.write(data)
    
    return q5_ans
