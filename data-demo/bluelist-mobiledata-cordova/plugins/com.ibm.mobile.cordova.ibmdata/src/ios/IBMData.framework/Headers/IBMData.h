//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------
//
//  IBMData.h
//  IBMData iOS SDK

#import <IBMBluemix/IBMBluemix.h>
#import <IBMData/IBMDataConstants.h>
#import <IBMData/IBMDataObject.h>
#import <IBMData/IBMDataObject+Specialize.h>
#import <IBMData/IBMQuery.h>
#import <IBMData/IBMUser.h>

#import <IBMData/IBMGeometry.h>
#import <IBMData/IBMPosition.h>
#import <IBMData/IBMPoint.h>
#import <IBMData/IBMLineString.h>
#import <IBMData/IBMPolygon.h>
#import <IBMData/IBMLinearRing.h>

/** This is the main class that connects to the Mobile Data service.

 Your app must initialize the Mobile Data service when your application starts.
 The typical place to perform this initialization is in the AppDelegate didFinishLaunchingWithOptions method.

	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
	{
		[IBMData initializeService];
	}
 */

@interface IBMData : IBMBluemixService

/** This method initializes the singleton instance of the Mobile Data Service for this application.

 @return (IBMData *) The IBMData instance for this application.
 */
+ (instancetype)initializeService;


/** This method initializes the singleton instance of the Mobile Data Service for this application.
 
 @return (IBMData *) The IBMData instance for this application.
 */
+ (instancetype)initializeService:(NSDictionary*)params;


/** This method returns the singleton instance of the Mobile Data Service for this application.
 
 @return (IBMData *) The IBMData instance for this application.
 */
+ (instancetype)service;

@end
