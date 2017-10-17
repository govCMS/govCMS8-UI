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
var browser = require('browser-sync');

// TODO add https://github.com/johanbrook/gulp-fontcustom
//          https://docs.npmjs.com/files/package.json
// Using OS X Iconical for now though,
// check the DESIGN folder

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
        .pipe(gulp.dest('./src/styles'))
        .pipe(browser.reload({ stream: true }));
});

// CSS concat, auto-prefix, optimise and minify
gulp.task('styles', function() {
    gulp.src(['./src/styles/colors.css'])
        .pipe(concat('./colors.css'))
        .pipe(autoprefix('last 2 versions'))
        .pipe(minifyCSS())
        .pipe(gulp.dest('./css/'))
        .pipe(browser.reload({ stream: true }));

});

// Reload the browser after a change to Twig files. Note this implementation does
// not do anything yet, need to rebuild cache after a change.
gulp.task('twig', function() {
  browser.reload();
});

// Set up a BrowserSync server to view changes on.

gulp.task('server', function() {
  browser.init({
    proxy: 'http://au.gov.dta.dev:8888/'
  });
});

// default gulp task
gulp.task('default', ['images', 'scripts', 'sass', 'styles', 'server'], function() {

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

    // watch for Twig changes
    gulp.watch('./templates/**/*.html.twig', function() {
        gulp.start('twig');
    });

});
