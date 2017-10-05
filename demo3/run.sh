#!/bin/bash
WSKURL=`bx wsk action get demo3/index --url | tail -n 1`
echo ${WSKURL}
curl ${WSKURL}

WSKURL=`bx wsk action get demo3/text --url | tail -n 1`
echo ${WSKURL}
curl -s ${WSKURL}

WSKURL=`bx wsk action get demo3/items --url | tail -n 1`
echo ${WSKURL}
curl -s ${WSKURL} | jq .