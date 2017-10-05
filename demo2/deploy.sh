#!/bin/bash
bx wsk action update demo2 function.js --kind nodejs:6 --web true
bx wsk action get demo2 --url
