(function ($, Drupal, drupalSettings) {

    'use strict';

    Drupal.behaviors.mybehavior = {
        attach: function (context, settings) {

            // Let's use bootstraps title display as it's much nicer!
            $('main.container [title]').each(function() {
                $(this).attr('data-toggle', 'tooltip');
                $(this).attr('data-placement', 'top');
            });
            $('[data-toggle="tooltip"]').tooltip();

        }
    };

})(jQuery, Drupal, drupalSettings);
