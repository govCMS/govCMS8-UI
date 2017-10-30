#!/usr/bin/env bash
cd "$(dirname "$0")"

ps -ef | grep gulp | grep -v grep | awk '{print $2}' | xargs kill

cd ../src/sass/uikit-bootstrap/

wget -N https://raw.githubusercontent.com/govCMS/uikit-bootstrap/master/sass/_vars.scss
wget -N https://raw.githubusercontent.com/govCMS/uikit-bootstrap/master/sass/_mixins.scss
wget -N https://raw.githubusercontent.com/govCMS/uikit-bootstrap/master/sass/_global.scss
wget -N https://raw.githubusercontent.com/govCMS/uikit-bootstrap/master/sass/_typography.scss
wget -N https://raw.githubusercontent.com/govCMS/uikit-bootstrap/master/sass/_elements.scss
wget -N https://raw.githubusercontent.com/govCMS/uikit-bootstrap/master/sass/_extra-elements.scss
wget -N https://raw.githubusercontent.com/govCMS/uikit-bootstrap/master/sass/_responsive.scss

echo "Updated!"

cd "$(dirname "$0")"
