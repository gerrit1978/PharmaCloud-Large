<?php

/**
 * Implements hook_rules_action_info().
 *
 * Registers an action for confirming an order's completion status to bpost.
 */
function commerce_bpost_rules_action_info() {
  $actions = array();

  // Define an action taking a commerce_order as parameter. When the action is
  // triggered, bpost will be notified that the order has been completed on our
  // end (usually after payment confirmation). This will cause the order status
  // in the shipping manager to go from 'Pending' to 'Open'.
  $actions['commerce_bpost_confirm_order'] = array(
    'label' => 'Send order confirmation to bpost',
    'group' => t('Commerce Shipping'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order to confirm to bpost'),
      ),
    ),
  );

  return $actions;
}
