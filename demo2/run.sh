#!/bin/bash
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"
set -x

WSKURL=`${WSKCLI} action get demo2 --url | tail -n 1`
echo ${WSKURL}
curl -k ${WSKURL}?name=NCDevCon17