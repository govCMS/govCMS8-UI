# govCMS Drupal 8 Theme
This is a theme for Drupal 8 govCMS based on the DTA UI Toolkit - implemented using [DTOstrap](https://fribibb.github.io/DTOstrap/).

## Work with it locally
### Requirements
- [npm](https://www.npmjs.com/)
- [git](https://git-scm.com/)

### Updating dta-ui-toolkit
To update the DTOstrap run the following...
`bash build/update_dtostrap.sh`
this fetches the latest Sass files from DTOstrap's Git repo. Then just run gulp to rebuild using them.

~~### Adding new color schemes
1. To add a new color scheme modify color/color.inc and include the new scheme as an array.

### Adding new fields to color schemes
1. Update color/color.inc and update the fields array with your new field
2. Update all schemes to include the new key and hex value
3. Update color/preview.html and color/preview.css to add the new 'regions' so that they are shown on the preview (on page load)
4. Update color/preview.js to take the value changed in the color picker and apply to the preview (on color picker change)
5. Update src/sass/_colors_govcms.scss and include the background-color / border-color's needed and make them match the color for the default scheme in color/color.inc~~
