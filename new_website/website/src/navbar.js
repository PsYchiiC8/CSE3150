// Navbar.js
import React from 'react';
import { Outlet, Link } from 'react-router-dom';

function Navbar() {
  return (
    <div>
      <nav>
        <Link to="/about" className='right'>About</Link>
        <Link to="/projects" className='right'>Projects</Link>
        <Link to="/" className='right'>Home</Link>

        <Link to="https://www.linkedin.com/in/kevin-huang-002149231" target="_blank" className="left">
          <img src="/linkedin.png" height={"42px"} alt="LinkedIn"></img>
        </Link>

        <Link to="mailto:kevin.3.huang@uconn.edu" target="_blank" className="left">
          <img src="/mail.png" height={"42px"} alt="Email"></img>
        </Link>
      </nav>
      <Outlet />
    </div>
  );
}

export default Navbar;
