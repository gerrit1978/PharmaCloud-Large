<?php

/**
 * @file
 * Preprocesses pages
 */

/**
 * Implements THEMENAME_preprocess_HOOK
 */
function apo_alpha_preprocess_page(&$vars) {

  if (drupal_is_front_page()) {
    $vars['title'] = "";
  }

}