/**
 * @file
 * Preview for the Bartik theme.
 */
(function ($, Drupal, drupalSettings) {

  'use strict';


  $('<iframe>', {
    src: document.location.origin,
    id:  'preview_iframe',
    frameborder: 0,
    scrolling: 'no',
    width: '100%',
    load:function(){
      iFrameLoaded();
    },
  }).appendTo('.color-preview');

  function iFrameLoaded() {
    var $colorPalette = $('.js-color-palette');
    var $colorPreview = $('#preview_iframe').contents();
    $colorPreview.find('#toolbar-administration').remove();
    $colorPreview.find('.contextual').each(function() {
      $(this).remove();
    });
    $colorPreview.find('a').each(function() {
      $(this).removeAttr("href").css("cursor","pointer");
    });

    $colorPalette.find("input[name^='palette']").each(function(){
      var bgColor = $(this).val();
      $(this).addClass('original-' + bgColor);
    });

    $('#preview_iframe').height( $('#preview_iframe').contents().find("body").height() );

    $("summary[aria-controls='color_scheme_form']").click();
  }

  Drupal.color = {

    logoChanged: false,
    callback: function (context, settings, $form) {
      var $colorPreview = $('#preview_iframe').contents();
      var $colorPalette = $form.find('.js-color-palette');

      var gradient_start = $colorPalette.find('input[name="palette[primarydarker]"]').val();
      var gradient_end = $colorPalette.find('input[name="palette[primaryalt]"]').val();

      $colorPreview.find('#header').attr('style', 'background-color: ' + gradient_start + '; background-image: -webkit-gradient(linear, 0% 0%, 0% 100%, from(' + gradient_start + '), to(' + gradient_end + ')); background-image: -moz-linear-gradient(-20deg, ' + gradient_start + ', ' + gradient_end + ');');

      $colorPalette.find("input[name^='palette']").each(function() {
        var originalHex = $(this).attr('class').match(/original-(.+)/);
        var newHex = $(this).val();
        if (originalHex != null) {
          originalHex = originalHex[1];
          $colorPreview.find('*').each(function () {
            var color = $(this).css('background-color');
            color = rgb2hex(color);
            if (color == originalHex) {
              $(this).css('background-color', newHex);
            }

            var color = $(this).css('color');
            color = rgb2hex(color);
            if (color == originalHex) {
              $(this).css('color', newHex);
            }

            var color = $(this).css('border-top-color');
            color = rgb2hex(color);
            if (color == originalHex) {
              $(this).css('border-top-color', newHex);
            }

            var color = $(this).css('border-bottom-color');
            color = rgb2hex(color);
            if (color == originalHex) {
              $(this).css('border-bottom-color', newHex);
            }

            var color = $(this).css('border-left-color');
            color = rgb2hex(color);
            if (color == originalHex) {
              $(this).css('border-left-color', newHex);
            }

            var color = $(this).css('border-right-color');
            color = rgb2hex(color);
            if (color == originalHex) {
              $(this).css('border-right-color', newHex);
            }


          });
        }
        $(this).removeClass('original-' + originalHex);
        $(this).addClass('original-' + newHex);
      });
    }
  };


  function rgb2hex(rgb) {
    if (rgb == null || rgb == 'transparent') return '';
    if (/^#[0-9A-F]{6}$/i.test(rgb)) return rgb;

    rgb = rgb.match(/^rgb\((\d+),\s*(\d+),\s*(\d+)\)$/);
    function hex(x) {
      return ("0" + parseInt(x).toString(16)).slice(-2);
    }
    return "#" + hex(rgb[1]) + hex(rgb[2]) + hex(rgb[3]);
  }
})(jQuery, Drupal, drupalSettings);
