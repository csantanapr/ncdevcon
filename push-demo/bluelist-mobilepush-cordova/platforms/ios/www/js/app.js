// Ionic Starter App

// angular.module is a global place for creating, registering and retrieving Angular modules
// 'starter' is the name of this angular module example (also set in a <body> attribute in index.html)
// the 2nd parameter is an array of 'requires'
// 'starter.services' is found in services.js
// 'starter.controllers' is found in controllers.js
 function alertNotification(notification) {
    var message;
    if(typeof notification === 'string'){
      message = JSON.parse(notification);
    } else {
      message = notification;
    }
    var alertMessage;
    if(message.alert){
      alertMessage = message.alert;
    } else {
      alertMessage =  JSON.stringify(message);
    }

    IBMBluemix.hybrid.getLogger().info("Received notification");
    //alert(alertMessage);
    showToast(alertMessage);

}
function showToast(msg){
    window.ionicLoading.show({
      template: msg,
      duration: 2000,
      noBackdrop: true
    });
}

angular.module('starter', ['ionic', 'starter.controllers', 'starter.services'])

.run(function($ionicPlatform, $http, $rootScope, $ionicLoading) {
  $ionicPlatform.ready(function() {
    // Hide the accessory bar by default (remove this to show the accessory bar above the keyboard
    // for form inputs)
    console.log('This is when all Cordova Plugins are ready');
    // Lets load the Configuration from the bluelist.json file
    $http.get('./bluelist.json').success(function(config) {

      // Initialise the SDK
      IBMBluemix.hybrid.initialize(config).done(function() {

        // Let the user no they have logged in and can do some stuff if they require
        console.log('Sucessful initialization with IBMBluemix Version : ' + IBMBluemix.hybrid.getVersion());

        // Initialize the Service

        IBMData.hybrid.initializeService().then(function(data) {

          console.log('IBM Data Initialized');
            $rootScope.dataService = data;
            if($rootScope.onRefresh){
              $rootScope.onRefresh();
            }

          }).
          catch (function(err) {
              console.error('IBM Data initialization failed', err);
        });
        IBMPush.hybrid.initializeService().then(function(push) {

          console.log('IBM Push Initialized');
          $rootScope.pushService = push;
          //Register the device
          push.registerDevice('Carlos Mobile', 'Carlos', 'alertNotification').done(function(response) {
              // Device successfully registered
              console.log('Device Register successfully with Bluemix Push Service');
          }, function(err) {
              // Handle errors
              console.log('Device Register failed to register with Bluemix Push Service');
          });

          }).
            catch (function(err) {
                console.error("IBM Data initialization failed", err);
        });

        // Let the user no they have logged in and can do some stuff if they require
        //console.log("Sucessful initialization Data Services ");

      }, function(response) {
        // Error
        console.log("Error:", response);

      });

    });

    if(window.cordova && window.cordova.plugins.Keyboard) {
      cordova.plugins.Keyboard.hideKeyboardAccessoryBar(true);
    }
    if(window.StatusBar) {
      // org.apache.cordova.statusbar required
      StatusBar.styleDefault();
    }
    //expose ionicLoading globally and in inherents scopes
    window.ionicLoading = $ionicLoading;
  });
})

.config(function($stateProvider, $urlRouterProvider) {

  // Ionic uses AngularUI Router which uses the concept of states
  // Learn more here: https://github.com/angular-ui/ui-router
  // Set up the various states which the app can be in.
  // Each state's controller can be found in controllers.js
  $stateProvider

    // setup an abstract state for the tabs directive
    .state('tab', {
      url: "/tab",
      abstract: true,
      templateUrl: "templates/tabs.html"
    })

    // Each tab has its own nav history stack:

    .state('tab.dash', {
      url: '/dash',
      views: {
        'tab-dash': {
          templateUrl: 'templates/tab-dash.html',
          controller: 'DashCtrl'
        }
      }
    })

    .state('tab.friends', {
      url: '/friends',
      views: {
        'tab-friends': {
          templateUrl: 'templates/tab-friends.html',
          controller: 'FriendsCtrl'
        }
      }
    })
    .state('tab.friend-detail', {
      url: '/friend/:friendId',
      views: {
        'tab-friends': {
          templateUrl: 'templates/friend-detail.html',
          controller: 'FriendDetailCtrl'
        }
      }
    })

    .state('tab.account', {
      url: '/account',
      views: {
        'tab-account': {
          templateUrl: 'templates/tab-account.html',
          controller: 'AccountCtrl'
        }
      }
    })

    .state('tab.list-index', {
        url: '/list',
        views: {
            'list-tab': {
                templateUrl: 'templates/list-index.html',
                controller: 'ListIndexCtrl'
            }
        }
    })

    .state('tab.about', {
        url: '/about',
        views: {
            'about-tab': {
                templateUrl: 'templates/about.html',
                controller: 'AboutCtrl'
            }
        }
    });

  // if none of the above states are matched, use this as the fallback
  $urlRouterProvider.otherwise('/tab/list');

});
