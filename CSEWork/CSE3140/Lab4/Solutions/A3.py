from flask import Flask

app = Flask(__name__)

@app.route('/')
def index():
    team_info = "Team Number: 9<br>Names: Kevin Huang, Joshua Kaplan"
    return team_info

if __name__ == '__main__':
    app.run(debug=True)
