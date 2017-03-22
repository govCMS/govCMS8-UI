<?php

/**
 * @file
 * Lists available colors and color schemes for the govCMS theme.
 */



$info = array(
    // Available colors and color labels used in theme.
    'fields' => array(
        'primarylight' => t('Primary Light'),
        'primarybright' => t('Primary Bright'),
        'primaryhighlight' => t('Primary Highlight'),
        'primaryalt' => t('Primary Alternative'),
        'primary' => t('Primary'),
        'primarydark' => t('Primary Dark'),
        'primarydarker' => t('Primary Darker'),
        'success' => t('Success'),
        'danger' => t('Danger'),
        'warning' => t('Warning'),
        'beta' => t('Beta'),
    ),
    // Pre-defined color schemes.
    'schemes' => array(
        'default' => array(
            'title' => t('DTA UI Kit (Default)'),
            'colors' => array(
                'primarylight' => '#dff4f8',
                'primarybright' => '#5bcbe3',
                'primaryhighlight' => '#00bfe9',
                'primaryalt' => '#27798b',
                'primary' => '#146577',
                'primarydark' => '#115361',
                'primarydarker' => '#043751',
                'success' => '#007554',
                'danger' => '#cc0000',
                'warning' => '#f9c642',
                'beta' => '#880e48',
            ),
        ),
        'govcms' => array(
            'title' => t('govCMS'),
            'colors' => array(
                'primarylight' => '#47b8ac',
                'primarybright' => '#458fb4',
                'primaryhighlight' => '#00bfe9',
                'primaryalt' => '#27798b',
                'primary' => '#146577',
                'primarydark' => '#115361',
                'primarydarker' => '#043751',
                'success' => '#007554',
                'danger' => '#cc0000',
                'warning' => '#f9c642',
                'beta' => '#880e48',
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
