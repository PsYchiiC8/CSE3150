from Crypto.PublicKey import RSA

rsa_key = RSA.generate(1024)
f = open("./e.key", "wb")
f.write(rsa_key.export_key("PEM"))
f.close()

f = open("./d.key", "wb")
f.write(rsa_key.public_key().export_key())
f.close()

print(rsa_key.publickey().export_key())