# OpenWhisk Web Actions demos for NCDevCon 2017 (Oct 7-8)

Slides: [TBD]()

# Setup and Install
- Easiest way to run demos is using IBM Functions SaaS, it has large Free tier (400,000 GBs)
- IBM Functions is IBM's offering of [Apache OpenWhisk](openwhisk.org) Serverless platform
- Signup at https://bluemix.net
Even after 30 days and entering a credit card the free tier applies every month.

## Setup the IBM Functions CLI Plugin
Setup the CLI following the instructions [here](https://console.bluemix.net/openwhisk/learn/cli)

Test IBM Functions CLI is working
```
bx wsk action invoke /whisk.system/utils/echo -p hello world -r
```
Outputs:
```json
{
        "hello": "world"
}
```

## Running Demos
Every demo has a `deploy.sh`, `run.sh` and `clean.sh` scripts

### [Demo 1](./demo1)
Simple Echo Action

### [Demo 2](./demo2)
Hello Web Action

### [Demo 3](./demo3)
Web Action `index` returns Web Page to Test APIs
Web Action `text`  returns HTML Componen using Cache-Control
Web Action `json`  returns JSON 

# License
[Apache 2.0](LICENSE.txt)