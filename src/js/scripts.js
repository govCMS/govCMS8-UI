(function ($, Drupal, drupalSettings) {

  'use strict';

  Drupal.behaviors.mybehavior = {
    attach: function (context, settings) {
      // Test whether the tooltip function exists. It will not if Bootstrap is disabled.
      if(typeof tooltip === 'function') {
        // Let's use bootstraps title display as it's much nicer!
        $('main.container [title]').each(function() {
          if ($(this).parents('.sf-dump, .kint').length) {
            // Need this to stop it running on our dump/kint commands which breaks expansions
            return;
          }
          $(this).attr('data-toggle', 'tooltip');
          $(this).attr('data-placement', 'top');
        });
        $('[data-toggle="tooltip"]').tooltip();
      }
    }
  };

})(jQuery, Drupal, drupalSettings);
