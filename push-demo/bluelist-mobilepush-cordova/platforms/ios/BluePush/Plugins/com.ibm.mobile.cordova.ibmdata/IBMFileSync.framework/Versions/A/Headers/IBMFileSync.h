//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

#import <IBMBluemix/IBMBluemix.h>
#import <IBMFileSync/IBMDataClient.h>
#import <IBMFileSync/IBMDataClientManager.h>
#import <IBMFileSync/IBMDataFile.h>
#import <IBMFileSync/IBMDataFileSystem.h>

/** This is the main class that connects to the Mobile File service.

 The IBMFileSync class is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.

 Your app must initialize the Mobile File service when your application starts.
 The typical place to perform this initialization is in the AppDelegate didFinishLaunchingWithOptions method.

	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
	{
		[IBMFileSync initializeService];
	}
 */

@interface IBMFileSync : IBMBluemixService

/**---------------------------------------------------------------------------------------
 * @name Getting the service instance
 * ---------------------------------------------------------------------------------------
 */

/** This method initializes the singleton instance of the Mobile Data File Service for this application.

 @return The instance of the initialized File Service
 */
+ (instancetype)initializeService;

/** This method returns the singleton instance of the Mobile Data File Service for this application.

 @return The instance of the File Service; if initialized
 */
+ (instancetype)service;

@end
