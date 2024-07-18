// Projects.js
import React from 'react';

function Projects() {
    return (
        <div>
            <body className='body'>
                <h1>Projects and Experiences</h1>
                <table style={{ width: '100%'}}>
                    <tr>
                        <td style={{ width: '85%', paddingLeft: '30px', paddingRight: '50px', paddingBottom: '30px' }}>
                            <b style={{fontSize: '20px'}}>Introduction to Transformers Final Project- Story Generation</b>

                            <br></br>

                            {/* TODO: Get dataset name and upload to github */}
                            <p style = {{ fontSize: '15px' }}>We finetuned a transformers model with the dataset TinyStories to generate small stories.
                                The goal of the project was to help fix the lack of creativity in storytelling and to finetune a model to potentially 
                                assist in making more stories that could be more creative than what we typically encounter. 
                                <br></br>
                                <br></br>
                                We were learning about transformers and AI for the first time so we learned a number of things.
                                For example, we used the GPT-2 model (a purely decoder model), and finetuned it with the TinyStories dataset.
                                During the training, we learned that there were many limitations with the hardware and the model of which we were using.
                                For example, the model of which we worked with wasn't very efficient, it took a lot of memory to even train, and
                                had a token limit of which we were not aware of. The dataset was also a little messy and was very large which made training hard and long
                                <br></br>
                                <br></br>
                                If I were to do this project all over again, I would find a smaller and cleaner dataset to use so it does not crash any hardware
                                and find a better model (perhaps GPT-3) that can give and take larger outputs as many of the training data inputs had more tokens than the model could handle.
                            </p>
                        </td>
                    </tr>

                    <tr>  
                        <td style={{ width: '85%', paddingLeft: '30px', paddingRight: '50px', paddingBottom: '30px'  }}>
                            <b style={{fontSize: '20px'}}>CSE3150 Final Project- Flight Simulator</b>

                            <br></br>

                            <p style = {{ fontSize: '15px' }}>
                                This project was done completely in C++ with a basic User Interface navigated using the keyboard in the terminal.
                                Using various design patterns and concepts, a basic application to search for flights from one city/airport to another
                                was made using Depth First Search. While there are some errors and may not fully function, the major components of the project
                                to search for flights and scrolling through options still work. The majority of the User Interface was provided, but the functionalities were implemented myself.
                            </p>
                        </td>
                    </tr>

                    <tr>
                        <td style={{ width: '85%', paddingLeft: '30px', paddingRight: '50px', paddingBottom: '30px'  }}>
                            <p>
                                dadsfasdfasdfasdf
                            </p>
                        </td>
                    </tr>

                    <tr>

                    </tr>
                </table>
            </body>
        </div>
    );
}

export default Projects;
