<?php

function govcmsui_preprocess_page(&$variables) {
    $coa_footer = theme_get_setting('govcmsui_coa_footer');
    if(!empty($coa_footer) && $coa_footer == 1) {
        $variables['coa_bottom'] = '/' . drupal_get_path('theme','govcmsui') . '/img/coas-dark.svg';
    }
}

function govcmsui_preprocess_block(&$variables) {
    $variables['content']['#attributes']['block'] = $variables['attributes']['id'];

    $coa = theme_get_setting('govcmsui_coa');
    if(!empty($coa)) {
        $variables['govlogo'] = '/' . drupal_get_path('theme','govcmsui') . '/img/' . $coa;
    }
}

function govcmsui_preprocess_menu__main(&$variables) {
    $nav_justified = theme_get_setting('govcmsui_navbar_justified');
    if(!empty($nav_justified) && $nav_justified == 1) {
        $variables['attributes']['class'][] = 'nav-justified';
    } else {
        $variables['attributes']['class'][] = 'nav-not-justified';
    }
}