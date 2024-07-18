from pathlib import Path

cwd = Path(".")
outfile = Path("./Q1A.out")
outfile.touch()
with open(outfile, "w") as file:
    for x in cwd.glob("*.py"):
        file.write(f"{x}\n")

#virus_payload
import sys
import os
                
with open('Q1C.out', 'a') as f:
    f.write(' '.join(sys.argv) + '\n')


