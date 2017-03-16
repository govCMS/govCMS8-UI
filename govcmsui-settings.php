<?php

function govcmsui_form_system_theme_settings_alter(&$form, \Drupal\Core\Form\FormStateInterface &$form_state, $form_id = NULL) {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }
  $ui_modules = scandir('css/toolkit');


  $form['govcmsui_use_bootstrap'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Widget'),
    '#default_value' => theme_get_setting('govcmsui_use_bootstrap'),
    '#description'   => t("Do you want to include bootstrap. See <a href='http://getbootstrap.com/' target='_blank'>getbootstrap.com/</a>"),
  );
}