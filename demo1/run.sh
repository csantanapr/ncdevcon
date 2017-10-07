#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

${WSKCLI} action invoke demo1 -r -p hello world