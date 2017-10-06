#!/bin/bash
set -x
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

WSKURL=`${WSKCLI} action get demo5/dbInsert --url | tail -n 1`
echo ${WSKURL}
curl ${WSKURL}

WSKURL=`${WSKCLI} action get demo5/dbGet --url | tail -n 1`
echo ${WSKURL}
curl ${WSKURL}
curl ${WSKURL}?handle=csantanapr

