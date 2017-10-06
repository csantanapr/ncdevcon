#!/bin/bash
set -x
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

${WSKCLI} package update demo5


${WSKCLI} action  update demo5/dbInsert dbInsert.js --param-file .credentials.write.json -p dbname friends --kind nodejs:6 --web true
${WSKCLI} action  get demo5/dbInsert --url


${WSKCLI} action  update demo5/dbGet dbGet.js --param-file .credentials.read.json -p dbname friends --kind nodejs:6 --web true
${WSKCLI} action  get demo5/dbGet --url


