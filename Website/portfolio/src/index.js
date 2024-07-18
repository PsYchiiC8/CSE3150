import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';
import { BrowserRouter, Route, Routes } from "react-router-dom";
import Navbar from "./navbar";
import About from "./about";
import Projects from "./projects";

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
	<div>
		<React.StrictMode>
			<BrowserRouter>
				<Routes>
					<Route path="/" element={<Navbar />}>
						<Route index element={<App />} />
						<Route path="about" element={<About />} />
						<Route path="projects" element={<Projects />} />
					</Route>
				</Routes>
			</BrowserRouter>
		</React.StrictMode>
	</div>
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
