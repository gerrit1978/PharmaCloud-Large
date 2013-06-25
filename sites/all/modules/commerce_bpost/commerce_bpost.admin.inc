<?php

/**
 * Form builder for the bpost account settings form.
 */
function commerce_bpost_settings_form() {
  $form['commerce_bpost'] = array(
    '#type' => 'fieldset',
    '#title' => t('Commerce bpost account settings'),
    '#collapsible' => TRUE,
  );
  $form['commerce_bpost']['commerce_bpost_account'] = array(
    '#type' => 'textfield',
    '#title' => t('Account'),
    '#description' => t('The bpost shipping manager account ID to use.'),
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_bpost_account', ''),
  );
  $form['commerce_bpost']['commerce_bpost_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Passphrase'),
    '#description' => t('The passphrase used when generating the SHA-256 checksum hash.'),
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_bpost_secret', ''),
  );

  return system_settings_form($form);
}

/**
 * Validation handler for the bpost account settings form.
 */
function commerce_bpost_settings_form_validate($form, $form_state) {
  if (!preg_match('/^\d{6}$/', $form_state['values']['commerce_bpost_account'])) {
    form_set_error('commerce_bpost_account', t('Please enter a valid 6-digit bpost account Id.'));
  }
}