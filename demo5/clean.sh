#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

${WSKCLI} action delete demo5/dbInsert
${WSKCLI} action delete demo5/dbGet
${WSKCLI} package delete demo5
