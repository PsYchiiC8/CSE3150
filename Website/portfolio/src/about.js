import { Link } from "react-router-dom";
import "./App.css"

function About() {
    return (
        <div>
            <body className="body">
            <h1>About Me</h1>
                <table style={{ width: '100%', paddingTop: '10px' }}>
                    <tr>
                        <td style={{ width: '40%', paddingLeft: '330px' }}>
                            {/* TODO: get image of self */}
                            <img src = "images/change this" class = "profile"></img>
                        </td>
                        <td style ={{ width: '100%', paddingRight: '330px', lineHeight : '30px' }}>
                            <p>
                                My name is Kevin Huang and I am a senior attending the University of Connecticut with an expected graduation date in May 2025.
                                I am a first-gen student majoring in Computer Science looking to potentially have a concentration in Software Design and Development with a minor in Mathematics.
                                I have many interests including- but not limited to- Artificial Intelligence and Robotics.
                                <br></br>
                                <br></br>
                                I am considering completing a Masters degree in Computer Science and potentially looking to do research.
                            </p>
                        </td>
                    </tr>
                </table>

                <h2>Skills</h2>

                <dl className = "indented">

                    <li class = "p">Programming</li>
                        <dd>Python, Java, C/C++</dd>

                        <dd><li>Front End</li></dd>
                            <dd><dd>HTML/CSS, ReactJS, UI/UX</dd></dd>

                        <dd><li>Other</li></dd>
                            <dd><dd>Github, Linux/Windows, AI/ML, Time Management</dd></dd>

                    <li>English</li>

                    <li>Chinese (Mandarin)</li>

                    <li>Microsoft Suite and similar applications</li>
                        <dd>Word, Powerpoint, and Excel</dd>

                    <li>Other:</li>
                        <dd>Communication, Teamwork, Agile</dd>
                </dl>

                <h3>Connect With Me!</h3>

                <table style = {{ width: '100%', paddingTop: '10px' }}>
                    <tr>
                        <td style = {{ width: '50%', paddingLeft: '360px' }}>
                            <Link to="https://www.linkedin.com/in/kevin-huang-002149231" target="_blank" className="left">
                                <img src="/linkedin.png" height={"42px"} alt="LinkedIn"></img>
                            </Link>
                        </td>

                        <td style = {{ width: '100%', paddingRight: '360px' }}>
                            <Link to="mailto:kevin.3.huang@uconn.edu" target="_blank" className="left">
                                <img src="/mail.png" height={"42px"} alt="Email"></img>
                            </Link>
                        </td>
                    </tr>
                </table>

                {/* Resume */}
                <p class = " ">Download or View My Resume <a href="/Resume.pdf" target = "_blank"> Here </a> </p>

            </body>
        </div>
    );
};
  
export default About;
  