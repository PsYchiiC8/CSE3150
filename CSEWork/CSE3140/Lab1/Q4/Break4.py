import hashlib
import string
import os, sys
import time

import Login
import subprocess


def PasswordCracker():

    startTime = time.time()
    print(startTime)

    #passwordList = open("MostCommonPWs", "r")
    #passwords = passwordList.split("\n")

    with open('gang') as f:
        members = [line.rstrip('\n') for line in f]
        memberList = list(members)

    with open('PwnedPWfile') as f:
        badPasswords = [line.rstrip('\n') for line in f]
        badPasswordList = list(badPasswords)
        passwordDictionary = dict(password.split(",") for password in badPasswordList)

    foundOne = False

    for member in memberList:

        if member in passwordDictionary:
            attempt = subprocess.run(["python3", "Login.pyc", member, passwordDictionary[member]], capture_output=True)
            stdout = attempt.stdout.decode('utf-8')
            if (stdout.find("successful") >= 0):
                name = "{}'s".format(member)
                print(name + " Password: " + passwordDictionary[member])
                foundOne = True
                break


    endTime = time.time()
    print(endTime)

if __name__ == "__main__":
    PasswordCracker()
