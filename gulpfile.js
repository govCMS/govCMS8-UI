// NOTES:
// https://markgoodyear.com/2014/01/getting-started-with-gulp/
// http://www.sitepoint.com/introduction-gulp-js/
// http://ilikekillnerds.com/2014/11/10-highly-useful-gulp-js-plugins-for-a-super-ninja-front-end-workflow/

// *************************
// SETUP STEPS:
//
// # brew|apt install node
// # [sudo] npm install -g gulp gulp-jshint gulp-imagemin gulp-notify gulp-autoprefixer gulp-minify-css gulp-compass gulp-uncss gulp-concat gulp-uglify casperjs phantomjs-prebuilt jshint
// # cd [path]/govcms-theme/govcms-theme/
// # [sudo] npm link gulp gulp-jshint gulp-imagemin gulp-notify gulp-autoprefixer gulp-minify-css gulp-compass gulp-uncss gulp-concat gulp-uglify jshint
//
// Then just run 'gulp' to watch directory for changes :)
//
// May encounter this on old Ubuntu: http://stackoverflow.com/questions/32490328/gulp-autoprefixer-throwing-referenceerror-promise-is-not-defined
// *************************


// include gulp
var gulp = require('gulp');
// include plug-ins
var jshint = require('gulp-jshint');
var imagemin = require('gulp-imagemin');
var notify = require('gulp-notify');
var autoprefix = require('gulp-autoprefixer');
var minifyCSS = require('gulp-minify-css');
var sass = require('gulp-sass');
var uncss = require('gulp-uncss');
var concat = require('gulp-concat');
var minifyCSS = require('gulp-minify-css');
var uglify = require('gulp-uglify');

// TODO add https://github.com/johanbrook/gulp-fontcustom
//          https://docs.npmjs.com/files/package.json
// Using OS X Iconical for now though,
// check the DESIGN folder
// fix up instructions above to take into account npm install.



// JS minify
gulp.task('scripts', function() {
    return gulp.src('./src/js/*.js')
        .pipe(uglify())
        .pipe(gulp.dest('./js/'));
});



// minify new images
gulp.task('images', function() {
    return gulp.src('./src/img/**/*')
        .pipe(imagemin({ optimizationLevel: 3, progressive: true, interlaced: true }))
        .pipe(gulp.dest('./img'))
});



// Compile the Sass
gulp.task('sass', function() {
    gulp.src('./src/sass/colors.scss')
        .pipe(sass({
            noCache: true
        }))
        .pipe(gulp.dest('./src/styles'));
});



// CSS concat, auto-prefix, optimise and minify
gulp.task('styles', function() {
    gulp.src(['./src/styles/colors.css'])
        .pipe(concat('./colors.css'))
        .pipe(autoprefix('last 2 versions'))
        .pipe(minifyCSS())
        .pipe(gulp.dest('./css/'));
});




// default gulp task
gulp.task('default', ['images', 'scripts', 'sass', 'styles'], function() {

    // watch for img optim changes
    gulp.watch('./src/img/*', function() {
        gulp.start('images');
    });
    gulp.watch('./src/img/clients/*', function() {
        gulp.start('images');
    });

    // watch for JS changes
    gulp.watch('./src/js/*.js', function() {
        gulp.start('scripts');
    });

    // watch for Sass changes
    gulp.watch('./src/sass/*.scss', function() {
        gulp.start('sass');
    });

    // watch for CSS changes
    gulp.watch('./src/styles/*.css', function() {
        gulp.start('styles');
    });

});
