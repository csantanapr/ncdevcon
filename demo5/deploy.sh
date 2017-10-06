#!/bin/bash
set -x
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

${WSKCLI} package update demo5


${WSKCLI} action  update demo5/dbInsert dbInsert.js --param-file .credentials.write.json -p dbname friends --kind nodejs:6 --web true
${WSKCLI} action  get demo5/dbInsert --url
${WSKCLI} api create --apiname "friends_ncdevcon" "/db" "/friends" POST demo5/dbInsert --response-type http
${WSKCLI} api create --apiname "friends_ncdevcon" "/db" "/friends" PUT demo5/dbInsert --response-type http

${WSKCLI} action  update demo5/dbGet dbGet.js --param-file .credentials.read.json -p dbname friends --kind nodejs:6 --web true
${WSKCLI} action  get demo5/dbGet --url
${WSKCLI} api create --apiname "friends_ncdevcon" "/db" "/friends" GET demo5/dbGet --response-type http

${WSKCLI} action  update demo5/dbDelete dbDelete.js --param-file .credentials.write.json -p dbname friends --kind nodejs:6 --web true
${WSKCLI} action  get demo5/dbDelete --url
${WSKCLI} api create --apiname "friends_ncdevcon" "/db" "/friends" DELETE demo5/dbDelete --response-type http