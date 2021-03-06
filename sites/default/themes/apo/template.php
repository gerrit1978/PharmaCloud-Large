<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/**
 * Removes the number of items from the facet.
 * This is necessary for the "price range" facet
 */
function apo_preprocess_facetapi_link_inactive(&$variables) {
  unset($variables['count']);
}

function apo_commerce_cart_empty_page() {
  return '<div class="cart-empty-page">' 
    . t('Your shopping cart is empty.')
    . '<br /><br />'
    . l(t('Go to our product catalog.'), 'producten')
    . '</div>';
}