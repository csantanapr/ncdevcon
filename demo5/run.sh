#!/bin/bash
set -x
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

WSKURL=`${WSKCLI} action get demo5/dbInsert --url | tail -n 1`
echo ${WSKURL}
#curl ${WSKURL}
WSKAPIGWURL=`${WSKCLI} api list /db /friends post -f | grep URL | awk -FURL: '{print $2}'`
curl -H "Content-Type: application/json" \
-X POST -d '{"handle":"csantanapr","name":"Carlos","project":"OpenWhisk"}' \
$WSKAPIGWURL
curl -H "Content-Type: application/json" \
-X POST -d '{"handle":"raymondcamden","name":"Raymond","project":"Cat Pics"}' \
$WSKAPIGWURL
curl -H "Content-Type: application/json" \
-X POST -d '{"handle":"macdonst","name":"Simon","project":"PhoneGap"}' \
$WSKAPIGWURL
curl -H "Content-Type: application/json" \
-X POST -d '{"handle":"johnwargo","name":"John","project":"VSCode"}' \
$WSKAPIGWURL

WSKURL=`${WSKCLI} action get demo5/dbGet --url | tail -n 1`
echo ${WSKURL}
#curl ${WSKURL}
#curl ${WSKURL}?handle=csantanapr
WSKAPIGWURL=`${WSKCLI} api list /db /friends get -f | grep URL | awk -FURL: '{print $2}'`
curl -s $WSKAPIGWURL | jq .

WSKURL=`${WSKCLI} action get demo5/dbDelete --url | tail -n 1`
echo ${WSKURL}
#curl ${WSKURL}
#curl ${WSKURL}?handle=csantanapr
WSKAPIGWURL=`${WSKCLI} api list /db /friends delete -f | grep URL | awk -FURL: '{print $2}'`
curl -s -X DELETE $WSKAPIGWURL?handle=csantanapr | jq .


