#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

${WSKCLI} action delete demo4/html
${WSKCLI} action delete demo4/form
${WSKCLI} package delete demo4
rm html.zip
rm form.zip