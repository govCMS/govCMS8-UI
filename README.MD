# govCMS Drupal 8 Theme

This is a theme for Drupal 8 govCMS based on the DTA's [UI Kit](https://github.com/govau/uikit).

## Work with it locally

The theme uses gulp.js to create a local server, compile Sass into CSS, inject style changes, and watch for SCSS, JavaScript and Twig changes. Install dependencies using NPM (Node Package Manager) before working on the theme.

You need a local server to develop sites on via BrowserSync.

### About gulp

Gulp automates the development workflow. To add a task, install the required plugin (if necessary), import it into gulpfile.js and script the task. There is a huge amount of plugins available for gulp so if you need to automate something it is probably possible. Check the list of [gulp recipes](https://github.com/gulpjs/gulp/tree/master/docs/recipes) for more ideas.

### Requirements

- [npm](https://www.npmjs.com/)
- [gulp](https://gulpjs.com/)

### Installation

1. Check that Node and NPM are installed using `$ node -v` and `$ npm -v`. If these are not installed, please install using Homebrew or use the instructions on the [Node.js site](https://nodejs.org/en/).
2. Install gulp globally using `$ npm install gulp-cli -g`.
3. Run `$ npm install` in the theme folder to install the required dependencies.
4. Update the URL in the `server` task to match your local environment.
5. Run `$ gulp` to start the build process.

### Updating dta-ui-toolkit
To update the dta UI Toolkit run the following...
Figure this bit out...

### Adding new color schemes
1. To add a new color scheme modify color/color.inc and include the new scheme as an array.

### Adding new fields to color schemes
1. Update color/color.inc and update the fields array with your new field
2. Update all schemes to include the new key and hex value
3. Update color/preview.html and color/preview.css to add the new 'regions' so that they are shown on the preview (on page load)
4. Update color/preview.js to take the value changed in the color picker and apply to the preview (on color picker change)
5. Update src/sass/_colors_govcms.scss and include the background-color / border-color's needed and make them match the color for the default scheme in color/color.inc
