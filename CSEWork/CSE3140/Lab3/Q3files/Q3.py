import sys
from Crypto.PublicKey import RSA
from Crypto.Hash import SHA256
from Crypto.Signature import PKCS1_v1_5
import subprocess
from pathlib import Path
import os


if __name__ == "__main__":
    cwd = Path(".")
    key_path = os.listdir("/home/cse/Lab3")

    key = "../Q3pk.pem"

    data = [x for x in cwd.glob("*.exe")]
    
    for file in data:
        output = subprocess.run(["python3", "verifier.py", key, file, (str(file) + ".sign")], capture_output = True, text = True)

        if "Success" in output.stdout:
            print(str(file), "Success")
        else:
            print(str(file), "Fail")
