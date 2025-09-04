import React from 'react';
import '../components/css/footer.css'; // Optional: create styles here

const Footer = () => {
  return (
    <footer className="site-footer">
      <div className="footer-content">
        <p>© {new Date().getFullYear()} UET Course Registration System. All rights reserved.</p>
        <p>
          <a href="https://courseregistrationsystemuet.netlify.app" target="_blank" rel="noopener noreferrer">
            Visit Our Website
          </a>
        </p>
      </div>
    </footer>
  );
};

export default Footer;