import sys
from Crypto.PublicKey import RSA
from Crypto.Hash import SHA256
from Crypto.Signature import PKCS1_v1_5

def verify_signature(key, data, sig):
    h = SHA256.new(data)
    rsa = RSA.importKey(key)
    signer = PKCS1_v1_5.new(rsa)
    with open(sig, 'rb') as f: signature = f.read()
    rsp = "Success" if (signer.verify(h, signature)) else " Verification Failure"
    print(rsp)

if __name__ == "__main__":
    key = sys.argv[1]
    data = sys.argv[2]
    sig = sys.argv[3]

    with open(key, 'rb') as f:
        key = f.read()
    with open(data, 'rb') as f:
        data = f.read()

    verify_signature(key, data, sig)