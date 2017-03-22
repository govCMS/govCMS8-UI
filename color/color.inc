<?php

/**
 * @file
 * Lists available colors and color schemes for the govCMS theme.
 */

$info = array(
  // Available colors and color labels used in theme.
  // Current ones not working
    /**
     * na
     */
  'fields' => array(
    'top' => t('Header background top'),
    'bottom' => t('Header background bottom'),
    'bg' => t('Main background'),
    'sidebar' => t('Sidebar background'),
    'sidebarborders' => t('Sidebar borders'),
    'footer' => t('Jumbo Footer background'),
    'footertext' => t('Jumbo Footer Text color'),
    'footerlinks' => t('Small Footer background'),
    'titleslogan' => t('Title and slogan'),
    'text' => t('Text color'),
    'link' => t('Link color'),
  ),
  // Pre-defined color schemes.
  'schemes' => array(
      'default' => array(
          'title' => t('DTA UI Kit'),
          'colors' => array(
              'top' => '#043751',
              'bottom' => '#227a97',
              'bg' => '#f3ffff',
              'sidebar' => '#ffffff',
              'sidebarborders' => '#ffffff',
              'footer' => '#3f7a9f',
              'footertext' => '#fffff0',
              'footerlinks' => '#f0f3f5',
              'titleslogan' => '#ffffff',
              'text' => '#313131',
              'link' => '#313131',
          ),
        'govcms' => array(
          'title' => t('govCMS (default)'),
          'colors' => array(
              'top' => '#458fb4',
              'bottom' => '#47b8ac',
              'bg' => '#f3ffff',
              'sidebar' => '#f6f6f2',
              'sidebarborders' => '#f9f9f9',
              'footer' => '#3f7a9f',
              'footertext' => '#fcf8f8',
              'footerlinks' => '#f0f3f5',
              'titleslogan' => '#fffeff',
              'text' => '#333333',
              'link' => '#3b7498',
          ),
        ),

    ),
  ),

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array(
    'css/colors.css',
  ),

  // Files to copy.
  'copy' => array(
    'logo.svg',
  ),


    // Gradient definitions.
  'gradients' => array(
    array(
      // (x, y, width, height).
      'dimension' => array(0, 0, 0, 0),
      // Direction of gradient ('vertical' or 'horizontal').
      'direction' => 'vertical',
      // Keys of colors to use for the gradient.
      'colors' => array('top', 'bottom'),
    ),
  ),

  // Preview files.
  'preview_library' => 'govcmsui/color.preview',
  'preview_html' => 'color/preview.html',

  // Attachments.
  '#attached' => [
    'drupalSettings' => [
      'color' => [
        // Put the logo path into JavaScript for the live preview.
        'logo' => theme_get_setting('logo.url', 'govcmsui'),
      ],
    ],
  ],
);
