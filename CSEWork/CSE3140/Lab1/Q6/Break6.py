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

    with open('SaltedPWs') as f:
        badPasswords = [line.rstrip('\n') for line in f]
        badPasswordList = list(badPasswords)
        passwordDictionary = list(password.split(",") for password in badPasswordList)

    with open('PwnedPWs100k') as f:
        pwnedPasswords = [line.rstrip('\n') for line in f]
        pwnedPasswordList = list(pwnedPasswords)

    gangHashes = {}
    gangSalts = []

    for member in memberList:
        for allLists in passwordDictionary:
            if allLists[0] == member:
                gangHashes[allLists[2]] = [member, allLists[1]]
                gangSalts.append(allLists[1])
                print("Member: " + member + ", Salt: " + allLists[1] + ", Hash: " + allLists[2])


    for pwnedPassword in pwnedPasswordList:

        for i in range(0,10):
            passwordAttempt = pwnedPassword + str(i)

            for salt in gangSalts:
                concat = salt + passwordAttempt
                attempt = hashlib.sha256(concat.encode('UTF-8'))
                stringer = attempt.hexdigest()
                if stringer in gangHashes.keys():
                    memberFinder = gangHashes[stringer][0]
                    print("Member: " + memberFinder + ", Password: " + passwordAttempt)
                    login = os.system('python3 Login.pyc ' + memberFinder + " " + passwordAttempt)

    endTime = time.time()
    print(endTime)

if __name__ == "__main__":
    PasswordCracker()

