#!/bin/bash
bx wsk package update demo3
bx wsk action  update demo3/index index.js --kind nodejs:6 --web true
bx wsk action  get demo3/index --url
bx wsk action  update demo3/text text.js --kind nodejs:6 --web true
bx wsk action  get demo3/text --url
bx wsk action  update demo3/json json.js --kind nodejs:6 --web true
bx wsk action  get demo3/json --url
