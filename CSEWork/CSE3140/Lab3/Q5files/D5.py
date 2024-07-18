from pathlib import Path
from Crypto.Hash import MD5
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad

BLOCKSIZE = 512
h = MD5.new()
content_bytes_path = Path("./R5.py")
with open(content_bytes_path , 'rb') as afile:
    buf = afile.read(BLOCKSIZE)
    while len(buf) > 0:
        h.update(buf)
        buf = afile.read(BLOCKSIZE)

hf = h.digest()
key = hf

with open("./Encrypted5", "rb") as f:
    iv = f.read(16)
    ct = f.read()

    cipher = AES.new(key, AES.MODE_CBC, iv)
    original_data = unpad(cipher.decrypt(ct), AES.block_size)

    with open("./decrypted", "wb") as f1:
        f1.write(original_data)