#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

WSKURL=`${WSKCLI} action get demo3/index --url | tail -n 1`
echo ${WSKURL}
curl ${WSKURL}

WSKURL=`${WSKCLI} action get demo3/text --url | tail -n 1`
echo ${WSKURL}
curl -s ${WSKURL}

WSKURL=`${WSKCLI} action get demo3/json --url | tail -n 1`
echo ${WSKURL}
curl -s ${WSKURL} | jq .