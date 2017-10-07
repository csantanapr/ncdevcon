#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

WSKURL=`${WSKCLI} action get demo6/html --url | tail -n 1`
echo ${WSKURL}
curl ${WSKURL}

