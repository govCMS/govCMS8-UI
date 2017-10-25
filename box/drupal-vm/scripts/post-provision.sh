#!/bin/bash

HOME_PATH="/home/vagrant"
GOVCMS_UI_PATH="/var/www/govcms-ui"

sudo rm -rf /var/www/govcms8/docroot/themes/contrib/govcms-ui
sudo ln -s $GOVCMS_UI_PATH /var/www/govcms8/docroot/themes/custom/govcms-ui
