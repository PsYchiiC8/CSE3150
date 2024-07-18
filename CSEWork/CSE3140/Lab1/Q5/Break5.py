import hashlib
import string
import os, sys
import time

import Login
import subprocess


def PasswordCracker():

    startTime = time.time()
    print(startTime)

    with open('gang') as f:
        members = [line.rstrip('\n') for line in f]
        memberList = list(members)

    with open('HashedPWs') as f:
        badPasswords = [line.rstrip('\n') for line in f]
        badPasswordList = list(badPasswords)
        passwordDictionary = dict(password.split(",") for password in badPasswordList)

    with open('PwnedPWs100k') as f:
        pwnedPasswords = [line.rstrip('\n') for line in f]
        pwnedPasswordList = list(pwnedPasswords)

    gangHashes = {}

    for member in memberList:
        if member in passwordDictionary.keys():
            gangHashes[member] = passwordDictionary[member]
            print("Member: " + member + ", Hash: " + passwordDictionary[member])


    for pwnedPassword in pwnedPasswordList:

        originalPlus0 = pwnedPassword + '0'
        for i in range(0,10):
            passwordAttempt = originalPlus0 + str(i)
            attempt = hashlib.sha256(passwordAttempt.encode('UTF-8'))
            if attempt.hexdigest() in gangHashes.values():
                for member in gangHashes:
                    if gangHashes[member] == attempt.hexdigest():
                        targetMember = member
                print("Member: " + str(targetMember) + ", Password: " + passwordAttempt)
                login = os.system('python3 Login.pyc ' + targetMember + " " + passwordAttempt)
                print(attempt)
        for i in range(10, 100):
            passwordAttempt = pwnedPassword + str(i)
            attempt = hashlib.sha256(passwordAttempt.encode('UTF-8'))
            if attempt.hexdigest() in gangHashes.values():
                for member in gangHashes:
                    if gangHashes[member] == attempt.hexdigest():
                        targetMember = member
                print("Member: " + str(targetMember) + ", Password: " + passwordAttempt)
                login = os.system('python3 Login.pyc ' + targetMember + " " + passwordAttempt)





    endTime = time.time()
    print(endTime)

if __name__ == "__main__":
    PasswordCracker()

