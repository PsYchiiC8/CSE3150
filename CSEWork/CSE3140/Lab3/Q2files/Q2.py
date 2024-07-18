import subprocess
import os
from pathlib import Path

i = 0
cwd = Path(".")
for filename in cwd.glob("*.exe"):
    output = subprocess.run(["sha256sum", filename], capture_output = True, text = True)
    
    if("fb16b0f8c646e85db82861b9668bc8421a36bef2d09e46f9dc4ef2b724be26b2" in output.stdout):
        print("match            ", filename, i)
    else:
        print("no match", filename, i)

    i += 1