#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

${WSKCLI} package update demo6

echo "exports.html = require('./html.js').main" > index.js
zip html.zip index.js package.json html.js index.html
${WSKCLI} action  update demo6/html html.zip --main html --kind nodejs:6 --web true
${WSKCLI} action  get demo6/html --url
${WSKCLI} api create --apiname "friends_ncdevcon_app" "/app" "/friends" GET demo6/html --response-type http

