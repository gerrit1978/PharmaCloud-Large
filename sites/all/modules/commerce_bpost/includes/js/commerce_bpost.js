(function ($) {
  function bpostPost() {
    // If it does not yet exists, create the hidden bpost form.
    if (!$('#bpostForm').length) {
      $('body').append('<div id="bpostForm"></div>');
    }

    // Load the form containing the hidden values to post to bpost, including
    // the checksum. We reload the form each time the button is pressed, since
    // it is possible that line items are added or order properties change
    // between successive clicks (for example by adding discount codes.)
    $('#bpostForm').load('/checkout/' + Drupal.settings.commerceBpost.orderid+ '/bpost-form', function() {
      // Show the bpost frame.
      $('#bpostForm form').submit();
    });
  }

  Drupal.behaviors.commerce_bpost = {
    attach: function(context, settings) {
      $("#logobpost").once().click(function() {
        bpostPost();
      });
    }
  }
})(jQuery);