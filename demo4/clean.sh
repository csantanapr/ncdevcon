#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

${WSKCLI} action delete demo4/index
${WSKCLI} action delete demo4/form
${WSKCLI} package delete demo4