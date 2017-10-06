#!/bin/bash
set -x
WSKCLI=${WSKCLI:="bx wsk"}
echo "Using CLI ${WSKCLI}"

WSKURL=`${WSKCLI} action get demo5/dbInsert --url | tail -n 1`
echo ${WSKURL}
#curl ${WSKURL}
WSKAPIGWURL=`bx wsk api list /db /friends post -f | grep URL | awk -FURL: '{print $2}'`
curl -H "Content-Type: application/json" -X POST -d '{"handle":"raymondcamden","name":"Raymond","project":"Cats"}' $WSKAPIGWURL

WSKURL=`${WSKCLI} action get demo5/dbGet --url | tail -n 1`
echo ${WSKURL}
#curl ${WSKURL}
#curl ${WSKURL}?handle=csantanapr
WSKAPIGWURL=`bx wsk api list /db /friends get -f | grep URL | awk -FURL: '{print $2}'`
curl $WSKAPIGWURL

WSKURL=`${WSKCLI} action get demo5/dbDelete --url | tail -n 1`
echo ${WSKURL}
#curl ${WSKURL}
#curl ${WSKURL}?handle=csantanapr
WSKAPIGWURL=`bx wsk api list /db /friends delete -f | grep URL | awk -FURL: '{print $2}'`
curl -X DELETE $WSKAPIGWURL?handle=raymondcamden


