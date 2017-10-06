#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
${WSKCLI} package update demo4

echo "exports.html = require('./html.js').main" > index.js
zip html.zip index.js package.json html.js index.html

${WSKCLI} action  update demo4/html html.zip --main html --kind nodejs:6 --web true
${WSKCLI} action  get demo4/html --url


echo "exports.form = require('./form.js').main" > index.js
zip form.zip index.js package.json form.js

${WSKCLI} action  update demo4/form form.zip --main form --kind nodejs:6 --web true
${WSKCLI} action  get demo4/form --url
