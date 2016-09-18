# Intro Ionic 2/Angular2 Demo for NCDevcon 2016 (Sept 17-18)

Slides [bit.ly/ionic-ncdevcon16](http://bit.ly/ionic-ncdevcon16)

### Running demo

#### Install stuff
```bash
npm install -g ionic@beta cordova ios-deploy
```

#### Run App in browser
```bash
ionic serve --lab
```

### Run App in Android
```bash
ionic platform add android
ionic run android
```

### Run App in iOS
```bash
ionic platform add android
open platforms/ios/*.xcodeproj
```
Use Select Play button and select a Simulator or a Device attached via USB

### Serverless Support
You can use this App using [OpenWhisk](https://new-console.ng.bluemix.net/openwhisk) Serveless action

First deploy your Severless function [searchVideo](https://github.com/csantanapr/openwhisk-demos/tree/master/searchVideo)

Then enter the configuration into the Serverless service [serverless-service.ts](./app/providers/serverless-service/serverless-service.ts)
```javascript
// Use the wsk cli to get this values with `wsk property get`
const API_HOST = "<REPLACE ME>"  //if running locally use your OpenWhisk host instead of bluemix.net
const API_KEY =  window.btoa('<REPLACE ME>');
const API_NAMESPACE = "<REPLACE ME>"
// The Severless Function name get this value with  `wsk action list`
const API_ACTION = "searchVideoAction"
```

And lastly change the [home.ts](./app/pages/home/home.ts)
```javascript
const useServerless = true;
```