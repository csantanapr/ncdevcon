#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

${WSKCLI} action delete demo3/index
${WSKCLI} action delete demo3/text
${WSKCLI} action delete demo3/json
${WSKCLI} package delete demo3