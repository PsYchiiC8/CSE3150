#!/usr/bin/env python3

from pathlib import Path

from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad


file_path = Path("./Encrypted4")
file = open(file_path, "rb")
iv = file.read(AES.block_size)
key = Path("./.key.txt").read_bytes()

cipher = AES.new(key, AES.MODE_CBC, iv=iv)
decrypted_data = unpad(cipher.decrypt(file.read()), AES.block_size)
print(str(decrypted_data, encoding="utf8"))
output_path = Path("./Q4a")
output_path.touch()
output_file = open(output_path, "w")
output_path.write_text(str(decrypted_data, encoding="utf8"))