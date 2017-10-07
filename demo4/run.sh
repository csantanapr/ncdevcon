#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

WSKURL=`${WSKCLI} action get demo4/html --url | tail -n 1`
echo ${WSKURL}
curl -k ${WSKURL}

WSKURL=`${WSKCLI} action get demo4/form --url | tail -n 1`
echo ${WSKURL}
curl -k -X POST ${WSKURL}
