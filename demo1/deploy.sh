#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

${WSKCLI} action update demo1 function.js --kind nodejs:6