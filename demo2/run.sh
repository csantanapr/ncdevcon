#!/bin/bash
WSKURL=`bx wsk action get demo2 --url | tail -n 1`
echo ${WSKURL}
curl ${WSKURL}