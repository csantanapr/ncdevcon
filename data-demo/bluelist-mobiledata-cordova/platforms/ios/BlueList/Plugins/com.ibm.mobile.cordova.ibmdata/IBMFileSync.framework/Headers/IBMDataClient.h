//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import "IBMDataClientManager.h"

/**
 * IBMDataClient singleton factory.
 *
 */
@interface IBMDataClient : NSObject

/**
 * IBMDataClientManager singleton factory method
 * @returns newly created IBMDataClientManager if doesn't exist or already created one.
 */
+ (IBMDataClientManager*)sharedManager;

@end
