#!/usr/bin/env bash
cd "$(dirname "$0")"

ps -ef | grep gulp | grep -v grep | awk '{print $2}' | xargs kill

cd src/sass/

wget -N https://raw.githubusercontent.com/fribibb/DTOstrap/master/sass/_dtostrap-vars.scss
wget -N https://raw.githubusercontent.com/fribibb/DTOstrap/master/sass/_dtostrap-mixins.scss
wget -N https://raw.githubusercontent.com/fribibb/DTOstrap/master/sass/_dtostrap-global.scss
wget -N https://raw.githubusercontent.com/fribibb/DTOstrap/master/sass/_dtostrap-typography.scss
wget -N https://raw.githubusercontent.com/fribibb/DTOstrap/master/sass/_dtostrap-elements.scss
wget -N https://raw.githubusercontent.com/fribibb/DTOstrap/master/sass/_dtostrap-responsive.scss

echo "Updated!"

cd "$(dirname "$0")"
