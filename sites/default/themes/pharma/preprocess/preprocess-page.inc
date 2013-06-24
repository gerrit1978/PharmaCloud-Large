<?php

/**
 * @file
 * Preprocesses nodes
 */

/**
 * Implements THEMENAME_preprocess_HOOK
 */
function pharma_alpha_preprocess_page(&$vars) {

  if (drupal_is_front_page()) {
    $vars['title'] = "";
  }

}