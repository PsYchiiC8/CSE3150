from Crypto.PublicKey import RSA

rsa_key = RSA.generate(1024)
f = open("./k.key", "wb")
f.write(rsa_key.export_key("PEM"))
f.close()
