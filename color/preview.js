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
    var $colorPreview = $('#preview_iframe').contents();
    $colorPreview.find('#toolbar-administration').remove();
    $colorPreview.find('.contextual').each(function() {
      $(this).remove();
    });
    $colorPreview.find('a').each(function() {
      $(this).removeAttr("href").css("cursor","pointer");
    });
    $('#preview_iframe').height( $('#preview_iframe').contents().find("body").height() );
  }

  Drupal.color = {

    logoChanged: false,
    callback: function (context, settings, $form) {
      var $colorPreview = $('#preview_iframe').contents();
      var $colorPalette = $form.find('.js-color-palette');

      var gradient_start = $colorPalette.find('input[name="palette[primarydarker]"]').val();
      var gradient_end = $colorPalette.find('input[name="palette[primaryalt]"]').val();

      $colorPreview.find('#header').attr('style', 'background-color: ' + gradient_start + '; background-image: -webkit-gradient(linear, 0% 0%, 0% 100%, from(' + gradient_start + '), to(' + gradient_end + ')); background-image: -moz-linear-gradient(-20deg, ' + gradient_start + ', ' + gradient_end + ');');
      $colorPreview.find('#header').find('#header').css('color', '#ffffff');

      // Solid background.
      $colorPreview.css('backgroundColor', $colorPalette.find('#ffffff').val());

      // Sidebar block.
      var $colorPreviewBlock = $colorPreview.find('.color-preview-sidebar .color-preview-block');
      $colorPreviewBlock.css('background-color', $colorPalette.find('input[name="palette[sidebar]"]').val());
      $colorPreviewBlock.css('border-color', $colorPalette.find('input[name="palette[sidebarborders]"]').val());

      // Footer wrapper background.
      $colorPreview.find('.color-preview-footer-wrapper').css('background-color', $colorPalette.find('input[name="palette[footer]"]').val());
      $colorPreview.find('.color-preview-footer-footer-wrapper').css('background-color', $colorPalette.find('input[name="palette[footerlinks]"]').val());
      $colorPreview.find('.color-preview-footer-wrapper').css('color', $colorPalette.find('input[name="palette[footertext]"]').val());
      $colorPreview.find('.color-preview-footer-wrapper a').css('color', $colorPalette.find('input[name="palette[footertext]"]').val());
    }
  };
})(jQuery, Drupal, drupalSettings);
