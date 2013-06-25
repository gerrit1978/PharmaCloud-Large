<?php

/**
 * Commerce checkout pane callback for the checkout form.
 */
function commerce_bpost_checkout_pane_checkout_form($form, &$form_state, $checkout_pane, $order) {
  return array(
    '#value' => theme('commerce_bpost_button', array('order' => $order))
  );
}

/**
 * Validation handler for the commerce bpost checkout pane.
 */
function commerce_bpost_checkout_pane_checkout_form_validate($form, &$form_state, $checkout_pane, $order) {
  // If bpost is required, do not allow a user to proceed if the order does not
  // have a bpost shipping line item.
  if (variable_get('commerce_bpost_required', FALSE) && !commerce_bpost_shipping_line_item($order)) {
    drupal_set_message(t('You cannot complete checkout without entering your delivery information via bpost.'), 'error');
    return FALSE;
  }

  return TRUE;
}

/**
 * Settings form for the commerce bpost checkout pane.
 */
function commerce_bpost_checkout_pane_settings_form($checkout_pane) {
  $form = array();

  $form['commerce_bpost_required'] = array(
    '#type' => 'checkbox',
    '#title' => t('Require that a user fills out and completes the bpost form.'),
    '#description' => t('Checking this option will prevent customers from completing checkout without completing the bpost delivery information. Make sure this is checked if your store only offers shipping through bpost.'),
    '#default_value' => variable_get('commerce_bpost_required', FALSE),
  );

  return $form;
}