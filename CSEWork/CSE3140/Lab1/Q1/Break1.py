import os
import subprocess
import time

if __name__ == "__main__":
    start = time.time()
    print(f"Start time: {start}")
    with open("./MostCommonPWs") as common_pws:
        for pw in common_pws:
            pw = pw[:-1]
            output = subprocess.run(["python3", "./Login.pyc", "Adam", pw], capture_output = True, text = True)
            if(output.stdout == 'Login successful.\n'):
                print("Success! pw is " + pw)
                break
            
    end = time.time()
    print(f"End time : {end}")
