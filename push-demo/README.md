## Demo for NCDevCon2014 Bluemix and Cordova using Cloud Push

### How to run demo

    npm install -g ionic cordova gulp
    git clone http://github.com/csantanapr/ncdevcon
    cd ncdevcon/bluelist-mobilepush-cordova
    edit app id to match yours configured with Push
    update www/bluelist.json with values from Bluemix.net
    npm install
    gulp install
    ionic platform ios
    ionic platform android
    ionic emulate android
    ionic emulate ios


### How to recreate demo

    npm install -g ionic cordova gulp
    #App ID: com.ibm.bluemix.bluepush.cordova
    #App Name: BlueList
    #App Project: bluelist-mobilepush-cordova
    #App Template: tabs
    ionic start -a BluePush -i com.ibm.bluemix.bluepush.cordova bluelist-mobilepush-cordova tabs
    cd bluelist-mobilepush-cordova/
    npm install
    gulp install
    ionic platform ios
    ionic platform android
    ionic plugin add com.ibm.mobile.cordova.ibmbluemix
    ionic plugin add com.ibm.mobile.cordova.ibmdata
    ionic plugin add com.ibm.mobile.cordova.ibmpush
    copy sample webapp for push into www/
    ionic emulate android -l
    ionic emulate ios -l

### Special configuration for iOS, modify Object-C code
To use the IBMPush Cordova plug-in for iOS, configure the AppDelegate of the Cordova application.

- Add the following property to the AppDelegate.h file:

    @property (nonatomic, strong) NSData* token;

- Add the following code snippets to the AppDelegate.m file. Import the IBM Push cordova header file.

    `// Import the header file.`

    `#import "CDVIBMPush.h"`

- Add the following code to the didFinishLaunchingWithOptions method to register your application to receive Push notifications.

    -(BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
    {
    // Register to receive remote notification
    [application registerForRemoteNotificationTypes:
    UIRemoteNotificationTypeBadge |
    UIRemoteNotificationTypeAlert |
    UIRemoteNotificationTypeSound];
    }


- Add the didRegisterForRemoteNotificationsWithDeviceToken method to receive the device token from the APNS service.

    -(void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken
    {
      // Set the device token to be passed onto Cordova plug-in.
      self.token = deviceToken;
    }

- Add the didFailToRegisterForRemoteNotificationsWithError method and provide your implementation to handle failure to receive device token from the APNS service.

    -(void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)err
    {
    //Failed to receive device token from APNS
    }

- Add the following method didReceiveRemoteNotification to receive the Push notification and pass it to your Cordova application.

    -(void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary*)userInfo
    {
    //Pass the notification to cordova to be sent back to the hybrid application.
    CDVIBMPush *pushhandler = [self.viewController getCommandInstance:@"IBMPushHybrid"];
    [pushhandler notificationReceived:userInfo];
    }

### Developer Notes

message is a string when callback(message) is executed for example:
"{
    alert = "NCDevCon2014 it's so Cool !";
    payload =     {
    };
}"
