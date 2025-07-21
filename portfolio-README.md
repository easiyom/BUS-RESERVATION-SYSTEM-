# Personal Portfolio Website

A modern, responsive personal portfolio website showcasing your projects and skills. This website is designed to highlight your Bus Reservation System project and provide space for future projects.

## Features

- **Modern Design**: Clean, professional layout with gradient accents
- **Fully Responsive**: Works perfectly on desktop, tablet, and mobile devices
- **Smooth Animations**: Scroll animations, typing effects, and hover interactions
- **Project Showcase**: Dedicated section highlighting your Bus Reservation System
- **Skills Display**: Animated skill bars showing your technical proficiencies
- **Contact Form**: Functional contact form with validation
- **Mobile Navigation**: Hamburger menu for mobile devices
- **SEO Friendly**: Semantic HTML structure

## Sections

1. **Hero Section**: Eye-catching introduction with animated code blocks
2. **About**: Personal introduction and statistics
3. **Projects**: Showcase of your Bus Reservation System and placeholders for future projects
4. **Skills**: Technical skills with animated progress bars
5. **Contact**: Contact information and form

## Customization Guide

### Personal Information
Update the following sections with your information:

#### Contact Details (in HTML)
```html
<!-- Update these placeholders in the contact section -->
<p>your.email@example.com</p>
<p>linkedin.com/in/yourprofile</p>
<p>github.com/yourusername</p>
```

#### Social Links (in HTML)
```html
<!-- Update href attributes in footer -->
<a href="https://github.com/yourusername"><i class="fab fa-github"></i></a>
<a href="https://linkedin.com/in/yourprofile"><i class="fab fa-linkedin"></i></a>
```

#### Project Links
- Update the Bus Reservation System project links to point to your actual GitHub repository
- Replace `href="#"` with your actual repository URL

### Adding New Projects

To add a new project, replace one of the placeholder project cards:

```html
<div class="project-card">
    <div class="project-header">
        <i class="fas fa-your-icon"></i>
        <h3>Your Project Name</h3>
    </div>
    <div class="project-content">
        <p>Project description...</p>
        
        <div class="project-features">
            <h4>Key Features:</h4>
            <ul>
                <li><i class="fas fa-check"></i> Feature 1</li>
                <li><i class="fas fa-check"></i> Feature 2</li>
            </ul>
        </div>
        
        <div class="tech-stack">
            <span class="tech-tag">Technology 1</span>
            <span class="tech-tag">Technology 2</span>
        </div>
        
        <div class="project-links">
            <a href="your-github-link" class="project-link">
                <i class="fab fa-github"></i> View Code
            </a>
            <a href="your-demo-link" class="project-link demo">
                <i class="fas fa-external-link-alt"></i> Live Demo
            </a>
        </div>
    </div>
</div>
```

### Updating Skills

Modify the skills section to reflect your actual skill levels:

```html
<div class="skill-item">
    <span>Skill Name</span>
    <div class="skill-bar">
        <div class="skill-progress" style="width: 85%"></div>
    </div>
</div>
```

### Color Scheme

The website uses a blue-purple gradient theme. To change colors, update these CSS variables:

```css
/* Main gradient colors */
background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);

/* Primary color */
color: #667eea;

/* Dark text color */
color: #2c3e50;
```

## File Structure

```
portfolio/
├── index.html          # Main HTML file
├── styles.css          # CSS stylesheet
├── script.js           # JavaScript functionality
└── portfolio-README.md # This documentation
```

## Technologies Used

- **HTML5**: Semantic markup
- **CSS3**: Modern styling with flexbox and grid
- **JavaScript**: Interactive functionality
- **Font Awesome**: Icons
- **Google Fonts**: Inter font family

## Browser Support

- Chrome (latest)
- Firefox (latest)
- Safari (latest)
- Edge (latest)

## Getting Started

1. Open `index.html` in a web browser to view your portfolio
2. Customize the content as described above
3. Replace placeholder links with your actual profiles
4. Add your own projects to the projects section
5. Host on GitHub Pages, Netlify, or your preferred hosting service

## Hosting Options

### GitHub Pages
1. Create a new repository
2. Upload all files
3. Go to Settings > Pages
4. Select source branch
5. Your site will be available at `username.github.io/repository-name`

### Netlify
1. Drag and drop the folder to Netlify
2. Your site will be automatically deployed

### Other Options
- Vercel
- Firebase Hosting
- Traditional web hosting

## Features to Add Later

- Blog section
- Dark mode toggle
- Multi-language support
- Project filtering
- Animation on load
- Performance optimizations

## Contact Form

The contact form currently shows a success message. To make it functional:

1. Use a service like Formspree, Netlify Forms, or EmailJS
2. Update the form action attribute
3. Add backend processing if needed

## Easter Egg

Try the Konami Code: ↑ ↑ ↓ ↓ ← → ← → B A

## License

This template is free to use for personal portfolios. Feel free to modify and customize as needed.

---

**Note**: Remember to update all placeholder content with your actual information before publishing your portfolio!