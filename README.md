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
Hello World Web Action with query parameter `name`

### [Demo 3](./demo3)
- Shows how to include HTTP headers including `Content-Type` and `Cache-Control`
- Shows how to repond with text or JSON
- Web Action `index` returns Web Page to Test APIs
- Web Action `text`  returns `text/html`
- Web Action `json`  returns `application/json`

### [Demo 4](./demo4)
- Shows how to Promises
- Shows how to read a local File
- Shows how to include files in Zip Action
- Shows how to include 2 actions in one Zip Action
- Shows how to access HTTP request Verb/Method
- Web Action `html`  returns a Web Form
- Web Action `form`  handles POST for Web Form

### [Demo 5](./demo5)
- Shows how to access CouchDB/Cloudant
- Shows how to create API endpoints in APIGateway
- Web Action `dbInsert`  handles POST/PUT to insert item into DataBase
- Web Action `dbGet`     handles GET to retrieve items from DataBase
- Web Action `dbDelete`  handles DELETE to destroy item from DataBase
- API `/db/friends` to handle POST, PUT, GET, DELETE

# License
[Apache 2.0](LICENSE.txt)