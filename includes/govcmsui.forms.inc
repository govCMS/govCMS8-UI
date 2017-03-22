<?php

/**
 * Implements hook_form_alter().
 */
function govcmsui_form_views_exposed_form_alter(&$form, \Drupal\Core\Form\FormStateInterface &$form_state, $form_id = NULL) {
    //Add CSS to form tag
    $form['#attributes'] = array('class' => array('form-inline', 'search-form'));

    //Hide label.. can't add classes directly to label so add span inside label... hackery
    $form['#info']['filter-search_api_fulltext']['label'] = '<span class="sr-only">Search</span>';
    //Add classes to input field
    $form['keywords']['#attributes']['class'][] = 'form-control';
    $form['keywords']['#attributes']['class'][] = 'input-lg';
    $form['actions']['submit'] = array(
        '#type' => 'item',
        '#markup' => '<button type="submit" id="edit-submit-2" name="op" value="Search" class="form-submit input-group-addon btn btn-lg"><i class="icon-search"></i><span class="sr-only">Search</span></button>',
        '#weight' => 1000,
        '#theme_wrappers' => array(),
    );
    $form['actions']['#prefix'] = '<div class="input-group input-group-btn">';
    $form['actions']['#suffix'] = '</div>';
}