import os
import shutil

##### Fix Permissions #####
os.system("chown cse:cse Q2dictionary.txt")
os.chmod("Q2dictionary.txt", 0o755)

os.system("chown cse:cse names.txt")
os.chmod("names.txt", 0o755)

os.mkdir("Solutions")
os.mkdir("LabGen")

os.system("chown cse:cse Solutions")
os.chmod("Solutions", 0o755)

os.system("chown cse:cse LabGen")
os.chmod("LabGen", 0o755)

shutil.move("Lab4Gen.py", "LabGen/")
