#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
${WSKCLI} package update demo4
zip demo4.zip index.js package.json html.js form.js index.html
${WSKCLI} action  update demo4/html demo4.zip --main html --kind nodejs:6 --web true
${WSKCLI} action  get demo4/index --url
${WSKCLI} action  update demo4/form demo4.zip --main form --kind nodejs:6 --web true
${WSKCLI} action  get demo4/form --url
