#!/bin/bash

GOVCMS_UI_PATH="/var/www/govcms8-ui"

sudo rm -rf /var/www/govcms8/docroot/themes/contrib/govcms-ui
ln -s $GOVCMS_UI_PATH /var/www/govcms8/docroot/themes/contrib/govcms-ui
sudo chown -R www-data:vagrant /var/www/govcms8/docroot/sites/default/files
