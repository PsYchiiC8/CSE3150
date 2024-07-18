from flask import Flask, render_template_string, request, make_response

app = Flask(__name__)

@app.route('/', methods=["GET"])
def index():
    url = "http://127.0.0.1:51818/loggedIn?username=ATj125&moneyAmount=5"
    return make_response(render_template_string(f"<img src={url} width='0' height='0'/>"))

if __name__=="__main__":
    app.run(debug=True)