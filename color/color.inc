<?php

/**
 * @file
 * Lists available colors and color schemes for the govCMS theme.
 */

$info = array(
  // Available colors and color labels used in theme.
  'fields' => array(
    'top' => t('Header background top'),
    'bottom' => t('Header background bottom'),
    'bg' => t('Main background'),
    'sidebar' => t('Sidebar background'),
    'sidebarborders' => t('Sidebar borders'),
    'footer' => t('Jumbo Footer background'),
    'footerlinks' => t('Small Footer background'),
    'titleslogan' => t('Title and slogan'),
    'text' => t('Text color'),
    'link' => t('Link color'),
  ),
  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('govCMS (default)'),
      'colors' => array(
        'top' => '#458fb4',
        'bottom' => '#47b8ac',
        'bg' => '#FFFFFF',
        'sidebar' => '#f6f6f2',
        'sidebarborders' => '#f9f9f9',
        'footer' => '#3F7A9F',
        'footerlinks' => '#f0f3f5',
        'titleslogan' => '#fffeff',
        'text' => '#333333',
        'link' => '#3b7498',
      ),
    ),
    'jason' => array(
      'title' => t('Jason'),
      'colors' => array(
        'top' => '#cd2d2d',
        'bottom' => '#d64e4e',
        'bg' => '#ffffff',
        'sidebar' => '#f1f4f0',
        'sidebarborders' => '#ededed',
        'footer' => '#1f1d1c',
          'footerlinks' => '#f0f3f5',
        'titleslogan' => '#fffeff',
        'text' => '#888888',
        'link' => '#d6121f',
      ),
    ),
    'joseph' => array(
      'title' => t('Joseph'),
      'colors' => array(
        'top' => '#d0d0d0',
        'bottom' => '#c2c4c5',
        'bg' => '#ffffff',
        'sidebar' => '#ffffff',
        'sidebarborders' => '#cccccc',
        'footer' => '#016b83',
          'footerlinks' => '#f0f3f5',
        'titleslogan' => '#000000',
        'text' => '#4a4a4a',
        'link' => '#019dbf',
      ),
    ),
    'paul' => array(
      'title' => t('Paul'),
      'colors' => array(
        'top' => '#4c1c58',
        'bottom' => '#593662',
        'bg' => '#fffdf7',
        'sidebar' => '#edede7',
        'sidebarborders' => '#e7e7e7',
        'footer' => '#2c2c28',
          'footerlinks' => '#f0f3f5',
        'titleslogan' => '#ffffff',
        'text' => '#301313',
        'link' => '#9d408d',
      ),
    ),
    'ruwan' => array(
      'title' => t('Ruwan'),
      'colors' => array(
        'top' => '#4a4a4a',
        'bottom' => '#4e4e4e',
        'bg' => '#ffffff',
        'sidebar' => '#ffffff',
        'sidebarborders' => '#d0d0d0',
        'footer' => '#161617',
          'footerlinks' => '#f0f3f5',
        'titleslogan' => '#ffffff',
        'text' => '#3b3b3b',
        'link' => '#0073b6',
      ),
    ),
    'tim' => array(
      'title' => t('Tim'),
      'colors' => array(
          'top' => '#d5078a',
          'bottom' => '#d3abc5',
          'bg' => '#815f75',
          'sidebar' => '#ffffff',
          'sidebarborders' => '#d0d0d0',
          'footer' => '#323acd',
          'footerlinks' => '#f0f3f5',
          'titleslogan' => '#ffffff',
          'text' => '#2f6043',
          'link' => '#0073b6',
      ),
    ),
  ),

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array(
    'css/colors.css',
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
