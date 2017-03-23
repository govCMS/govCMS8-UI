<?php

/**
 * Implements hook_form_alter().
 */
function govcmsui_form_views_exposed_form_alter(&$form, \Drupal\Core\Form\FormStateInterface &$form_state, $form_id = NULL) {
    if($form_id == 'views_exposed_form' && $form['#id'] == 'views-exposed-form-search-page') {
        $variables['block_html_id'] = "search";

        //Add CSS to form tag
        $form['#attributes'] = array('class' => array('pull-right'));
        //$form['keywords']['#theme'][] = 'exposed_search';

        //Hide label.. can't add classes directly to label so add span inside label... hackery
        $form['#info']['filter-search_api_fulltext']['label'] = '<span class="sr-only">Search</span>';
        $form['actions']['submit'] = array(
            '#type' => 'item',
            '#markup' => '<button type="submit" id="edit-submit-2" name="op" value="Search" class="form-submit input-group-addon btn btn-lg"><i class="icon-search"></i><span class="">Search</span></button>',
            '#weight' => 1000,
            '#theme_wrappers' => array(),
        );
        //dump($form);
    }

}