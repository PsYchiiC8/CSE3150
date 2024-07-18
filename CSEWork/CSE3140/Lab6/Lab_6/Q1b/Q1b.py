from flask import Flask, render_template, redirect, request, make_response, render_template_string

app = Flask(__name__)

@app.route("/post_handler", methods=['POST'])
def post_handler():
    if request.method == 'POST':
        netid = request.form['netId']
        lastname = request.form['lastName']
        vm_ip = request.remote_addr
        
        resp = make_response(redirect('http://127.0.0.1:3000/logged_in', code=301))
    
        resp.set_cookie('Q1b1', netid)
        resp.set_cookie('Q1b2', lastname, path="/Q1b2")
        resp.set_cookie('Q1b3', vm_ip, samesite="Lax")
        
        return resp
    
@app.route("/", methods=["GET"])
def home():
    if(request.cookies.get('Q1b3') == request.remote_addr):
        return redirect('http://127.0.0.1:3000/logged_in', code=301)
    else:
        return redirect('http://127.0.0.1:3000/Q1b', code=301)
        
@app.route("/Q1b")
def Q1b():
    return render_template('Q1b.html')

@app.route("/husky")
def husky():
    return redirect('http://127.0.0.1:3000/Q1b', code=301)

@app.route("/sign_out")
def sign_out():
    resp.delete_cookie('Q1b1')
    resp.delete_cookie('Q1b2', path="/Q1b2")
    resp.delete_cookie('Q1b3')
    resp = make_response(redirect('http://127.0.0.1:3000/Q1b', code=301))
    
    
    
    return resp

@app.route("/logged_in")
def loggedIn():
    return render_template('logged_in.html')

@app.route("/Q1b2")
def Q1b2():
    return render_template_string("<p>Welcome to Q1b2!!!<p>")