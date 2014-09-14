Mobile Cloud Services Push Cordova SDK for IBM Bluemix
===

This package contains the required native components to interact with the IBM
Bluemix Mobile Cloud Services.  This JavaScript SDK can be used for building Web
or Hybrid applications.  The SDK manages all the communication and security integration between
the client and with the Mobile Cloud Services in Bluemix.

When you use Bluemix to create a Mobile Cloud Starter application, BlueMix provisions
multiple services under a single application context. Your mobile application is given
access to the following mobile services: Mobile Application Security, Push, and Mobile Data.

The Mobile Cloud Services Push SDK is a Cordova SDK you can use inside a Cordova
or IBM Worklight application. The `IBMPush` SDK manages push notification through IBM Bluemix. This service is backed by Xtify and offers industry strenght push notifciations for IOS and Android. The Hybrid plugin allows the subscription to these notification.

Version: 1.0.0-20140910-1402

##Installation
The SDK may be installed either by downloading a [zip file](https://mbaas-catalog.ng.bluemix.net/sdk/ibm-bluemix-sdk-cordova.zip),
or by installing the desired components using the [Cordova](http://cordova.apache.org/) tools.
Using these tools can significantly shorten the startup time for new
projects and lessen the burden of managing library version requirements
as well as the dependencies between them.  If you
are using one of our [samples](https://hub.jazz.net/user/mobilecloud),
instructions for using the package manager is included with the documentation.

The Mobile Cloud Services SDK is a Cordova SDK you can use inside a Cordova or IBM Worklight
application.

To create add a plugin to your project, you first need to have installed the Cordova tools and created a project. You can find more information on how to achieve this from the Cordova project [Command Line Interface](http://cordova.apache.org/docs/en/3.5.0/guide_cli_index.md.html#The%20Command-Line%20Interface)

Adding the plugin to your project

```bash
cordova plugin add com.ibm.mobile.cordova.ibmpush
```

Removing the plugin from your project

To uninstall the plugin use the following cordova command

```bash
cordova plugin remove com.ibm.mobile.cordova.ibmpush
```

###Getting Started

Detailed instructions of how to use the plugin can be found in the [Hybrid Getting Started Guide](https://mbaas-gettingstarted.stage1.ng.bluemix.net/hybrid)

###Download

To download a zip of the entire SDK, visit the Mobile Cloud [starter page](https://www.ng.bluemix.net/docs/#starters/mobile/index.html#index).

### Manual Installation

IBM Worklight is a Cordova based Hybrid application platform. You can find more information
about IBM Worklight at this link [IBM Worklight Foundation](http://www-03.ibm.com/software/products/en/worklight-foundation)

Detailed instructions of how to install the plugin inside an IBM Worklight development environment
can be found in the [Getting Started Guide](https://mbaas-gettingstarted.stage1.ng.bluemix.net/hybrid)

###Contents

The complete SDK consists of a core, plus a collection of modules that correspond to function exposed
by the Mobile Cloud Services.  The downloaded zip file
contains all of them. However, each piece of the JavaScript SDK is also available as a separate module
that you can add to your project individually. This allows maximum flexibility, as the developer is able to
pick and choose the modules required for a given application.

The Hybrid JavaScript SDK uses the underlying Cordova runtime to hosting your hybrid application. This SDK then forms a bridge between the Web View and the Mobile Starter Native SDK. With this library you can:

- Reuse the code that is implemented within the Native toolkits, offering a single point of interaction between the Hybrid application and the BlueMix services.
- Use a single native domain for communication. Take advantage of a single point of security when communicating with BlueMix.
- Maintain security state of your application if the WebView is restarted on iOS (Apple 10 second rule).
- Reduce memory overhead of the WebView because less JavaScript is required for the the communication.
- Communicate through the same technology channel with both both Native and Hybrid (Cross Platform) content.
- Improve performance when you are using the Native tier of the application for processing of requests.


The Cordova SDK contains the following components, any of which may be added to your project.

- **[ibmbluemix](https://hub.jazz.net/project/bluemixmobilesdk/ibmbluemix-javascript/overview)** - This is the foundation of the SDK and controls connection and communication with Backend services
- **[ibmpush](https://hub.jazz.net/project/bluemixmobilesdk/ibmpush-javascript/overview)** - This is the service SDK for push notification support
- **[ibmdata](https://hub.jazz.net/project/bluemixmobilesdk/ibmdata-javascript/overview)** - This is the service SDK for cloud data storage
- **[ibmcloudcode](https://hub.jazz.net/project/bluemixmobilesdk/ibmcloudcode-javascript/overview)** - This is the service SDK for cloud code invocation

### Supported Platforms
- Android
- iOS

##Getting Started:

Services are associated with a Mobile Cloud application. Connectivity and interaction with
these services depends on the application id, application secret, and application route associated
with a Mobile Cloud Application.

IBMBluemix is the entry point for interacting with the Mobile Cloud Services SDKs.  The method initialize
must be invoked before any other API calls.  IBM Bluemix provides information about the current SDK level
and access to service SDKs.

##Learning More
- **[Mobile Cloud Services SDK Developer Guide](http://mbaas-gettingstarted.ng.bluemix.net/hybrid)**
- **[Hybrid API Reference](https://mobile.ng.bluemix.net/mbaas-api/docs/JavaScript/index.html)**
- **[Samples and Tutorials](https://www.ng.bluemix.net/docs/#starters/mobile/index.html#samples)**
- Visit the **[Bluemix Developers Community](https://developer.ibm.com/bluemix/)**

To learn more about Cordova and its related services and plugins, please consult the following resources:
- **[Cordova Documentation](http://cordova.apache.org/docs/en/3.0.0/guide_overview_index.md.html#Overview)**
- **[Cordova plugin development guide](http://cordova.apache.org/docs/en/2.2.0/guide_plugin-development_index.md.html#Plugin%20Development%20Guide)**

Connect with Bluemix: [Twitter](https://twitter.com/ibmbluemix) |
[YouTube](https://www.youtube.com/playlist?list=PLzpeuWUENMK2d3L5qCITo2GQEt-7r0oqm) |
[Blog](https://developer.ibm.com/bluemix/blog/) |
[Facebook](https://www.facebook.com/ibmbluemix) |
[Meetup](http://www.meetup.com/bluemix/)

*Licensed Materials - Property of IBM
(C) Copyright IBM Corp. 2013, 2014. All Rights Reserved.
US Government Users Restricted Rights - Use, duplication or
disclosure restricted by GSA ADP Schedule Contract with IBM Corp.*

[Terms of Use](https://hub.jazz.net/project/bluemixmobilesdk/ibmbluemix-android/overview#https://hub.jazz.net/gerrit/plugins/gerritfs/contents/bluemixmobilesdk%252Fibmbluemix-android/refs%252Fheads%252Fmaster/License.txt) |
[Notices]()
