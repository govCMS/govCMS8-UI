<?php

function govcmsui_js_alter(&$javascript, \Drupal\Core\Asset\AttachedAssetsInterface $assets) {
    // Swap out jQuery to use an updated version of the library.
    if(theme_get_setting('govcmsui_use_bootstrap') || theme_get_setting('govcmsui_use_jquery')) {
        $javascript['//cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js'] = array(
            'weight' => 0,
            'group' => -98,
            'version' => '3.1.1',
            'type' => 'external',
            'cache' => true,
            'preprocess' => true,
            'browsers' => array(),
            'scope' => 'footer',
            'attributes' => array(),
            'data' => '//cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js',

        );
    }
    if(theme_get_setting('govcmsui_use_bootstrap')) {
        $javascript['//cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/3.3.7/js/bootstrap.min.js'] = array(
            'weight' => 0,
            'group' => -99,
            'version' => '3.3.7',
            'type' => 'external',
            'cache' => true,
            'preprocess' => true,
            'browsers' => array(),
            'scope' => 'footer',
            'attributes' => array(),
            'data' => '//cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/3.3.7/js/bootstrap.min.js',

        );
    }
}

function govcmsui_css_alter(&$css, \Drupal\Core\Asset\AttachedAssetsInterface $assets) {
    if(theme_get_setting('govcmsui_use_bootstrap')) {
        $css['//cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/3.3.7/css/bootstrap.min.css'] = array(
            'weight' => 0,
            'group' => -99,
            'version' => '3.3.7',
            'type' => 'external',
            'preprocess' => true,
            'browsers' => array(),
            'media' => 'all',
            'data' => '//cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/3.3.7/css/bootstrap.min.css',

        );
    }
}


/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function govcmsui_theme_suggestions_menu_alter(array &$suggestions, array $variables) {
    // Remove the block and replace dashes with underscores in the block ID to
    // use for the hook name.
    if (isset($variables['attributes']['block'])) {
        $hook = str_replace(array('block-', '-'), array('', '_'), $variables['attributes']['block']);
        $suggestions[] = $variables['theme_hook_original'] . '__' . $hook;
    }
}

function govcmsui_theme_suggestions_block_alter(array &$suggestions, array $variables) {
    if (!empty($variables['elements']['#id'])) {
        $block = \Drupal\block\Entity\Block::load($variables['elements']['#id']);
        $suggestions[] = 'block__' . $block->getRegion() . '__' . $variables['elements']['#id'];
    }
    /* Use this 'else if' only if you are using page_manager module and want to know which region is the block */
    else if (isset($variables['elements']['#configuration']['region'])) {
        $suggestions[] = 'block__page_' . $variables['elements']['#configuration']['region'] . '__' . end(explode(':', $variables['elements']['#plugin_id']));
    }
    return $suggestions;
}