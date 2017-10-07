#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

${WSKCLI} action update demo2 function.js --kind nodejs:6 --web true
${WSKCLI} action get demo2 --url
