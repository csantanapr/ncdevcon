#!/bin/bash
set -x

WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

${WSKCLI} action delete demo5/dbInsert
${WSKCLI} action delete demo5/dbGet
${WSKCLI} action delete demo5/dbDelete
${WSKCLI} package delete demo5
${WSKCLI} api delete "/db"
