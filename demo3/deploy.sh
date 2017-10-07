#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

${WSKCLI} package update demo3
${WSKCLI} action  update demo3/index index.js --kind nodejs:6 --web true
${WSKCLI} action  get demo3/index --url

${WSKCLI} action  update demo3/text text.js --kind nodejs:6 --web true
${WSKCLI} action  get demo3/text --url

${WSKCLI} action  update demo3/json json.js --kind nodejs:6 --web true
${WSKCLI} action  get demo3/json --url
