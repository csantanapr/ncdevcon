#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

${WSKCLI} action delete demo6/html
${WSKCLI} package delete demo6
rm html.zip