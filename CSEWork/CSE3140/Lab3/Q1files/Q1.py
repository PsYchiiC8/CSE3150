import subprocess
import os
from pathlib import Path

i = 0
cwd = Path(".")
for filename in cwd.glob("*.exe"):
    output = subprocess.run(["sha256sum", filename], capture_output = True, text = True)
    
    if("05fa4bced4d0e5e841e151491a452f27737d70360320cf27abda3b112a92d687" in output.stdout):
        print(filename, i, "match")
        break
    else:
        print(filename, i, "no match")

    i += 1