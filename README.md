# OpenWhisk Web Actions - [NCDevCon 2017](http://ncdevcon.com/) (Oct 7-8)

Slides: [bit.ly/ncdevcon17](http://bit.ly/ncdevcon17)

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
- Setup couchdb/cloudant write credentials by renaming `.credentials.write.json.template` to `.credentials.write.json`
- Setup couchdb/cloudant read credentials by renaming `.credentials.read.json.template` to `.credentials.read.json`
- Shows how to access CouchDB/Cloudant
- Shows how to create API endpoints in APIGateway
- Web Action `dbInsert`  handles POST/PUT to insert item into DataBase
- Web Action `dbGet`     handles GET to retrieve items from DataBase
- Web Action `dbDelete`  handles DELETE to destroy item from DataBase
- Single API endpoint `/db/friends` to handle POST, PUT, GET, DELETE

### Demo 6
Map custom domain name to your API using API Gateway

This will allow you to expose your api like `https://api.csantanapr.com/db/friends`

1. Generate a certificate and private key for your domain name:
    - One of the easiest way is to use [LetsEncrypt](https://letsencrypt.org/)
    - I used my Mac from home.
    - Go to your DNS provider for your domain and create an A record to map your domain `api.csantanapr.com` to your public IP Address from your home router.
    - Configure your router to forward port `443` to the your Mac.
    - Turn off the firewall only while you are generating your certificate.
    - Install [CertBot](https://certbot.eff.org/#osx-other) CLI
    - Run the certbot, for example in stand-alone to run it's own web server
      ```
      sudo certbot certonly --standalone -d api.csantanapr.com
      ```
    - This will generate the certificate and private key
       ```
        Congratulations! Your certificate and chain have been saved at:
        /etc/letsencrypt/live/api.csantanapr.com/fullchain.pem
        Your key file has been saved at:
        /etc/letsencrypt/live/api.csantanapr.com/privkey.pem
       ```

2. Upload your Certificate and Private Key
    - Got to your Organization in Bluemix
    Manage->Account->Organizations from the top right corner of the Console.
    - Click `View Details` next to your organization
    - Click `Edit Org` next to your organization
    - Click `Domain` at the top bar
    - Click `Add Domain` button
    - Enter your domain in the first row `CUSTOM DOMAINS`
    - Click `SAVE`
    - Click the icon to Upload Certificate under the second row `SSL CERTIFICATES`

3. Select the Domain with your API in the API Gateway UI
    - Go to the [API Gateway Console](https://console.bluemix.net/openwhisk/apimanagement?env_id=ibm%3Ayp%3Aus-south)
    - Select the API to configure 
    - Select API Definition in the navigation column
    - Your new domain name will now show in the list of API Domain
    - Select you new domain from the drop down list
    - Scroll to the bottom and click `Save`
    - It takes about 5 minutes to be active 

# License
[Apache 2.0](LICENSE.txt)