(function ($) {

  Drupal.behaviors.promoCycle = {
    attach: function (context, settings) {
      $('.front ul.promo-items').carouFredSel({
        scroll: {
          fx: "fade"
        },
        auto: {
          timeoutDuration: 7500
        }
      });
    }
  };
  

})(jQuery);