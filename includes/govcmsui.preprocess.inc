<?php

function govcmsui_preprocess_page(&$variables) {
    $coa_footer = theme_get_setting('govcmsui_coa_footer');
    if(!empty($coa_footer) && $coa_footer == 1) {
        $variables['coa_bottom'] = '/' . drupal_get_path('theme','govcmsui') . '/img/coas-dark.svg';
    }

    $footer_copyright = theme_get_setting('govcmsui_footer_copyright');
    if(!empty($footer_copyright)) {
        $variables['footer_copyright'] = $footer_copyright;
    }
}

function govcmsui_preprocess_block(&$variables) {
    $variables['content']['#attributes']['block'] = $variables['attributes']['id'];
    $block_id = $variables['elements']['#id'];
    $block = \Drupal\block\Entity\Block::load($block_id);
    $variables['content']['#attributes']['region'] = $block->getRegion();

    $coa = theme_get_setting('govcmsui_coa');
    if(!empty($coa)) {
        $variables['govlogo'] = '/' . drupal_get_path('theme','govcmsui') . '/img/' . $coa;
    }
    if (!empty($variables['elements']['#id']) && $variables['base_plugin_id'] == 'views_exposed_filter_block') {
        $variables['attributes']['id'] = 'search';
    }
}

function govcmsui_preprocess_menu(&$variables) {
    if(isset($variables['attributes']['region'])) {
        $variables['content']['#attributes']['region'] = $variables['attributes']['region'];
    }
}

function govcmsui_preprocess_menu__main(&$variables) {
    if(isset($variables['attributes']['region'])) {
        $variables['content']['#attributes']['region'] = $variables['attributes']['region'];
    }

    $nav_justified = theme_get_setting('govcmsui_navbar_justified');
    if(!empty($nav_justified) && $nav_justified == 1) {
        $variables['attributes']['class'][] = 'nav-justified';
    }
}
