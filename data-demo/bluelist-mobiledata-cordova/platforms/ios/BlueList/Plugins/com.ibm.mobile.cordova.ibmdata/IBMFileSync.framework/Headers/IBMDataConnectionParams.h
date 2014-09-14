//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

/**
 * It contains the parameters passed in the connect method of the Cloud Manager or Storage Provider.
 *
 */
@protocol IBMDataConnectionParams <NSObject>

/**
 * Dictionary representation of parameters.
 * @returns Dictionary containing the parameters passed in the connect method.
 */
-(NSDictionary*)toDictionary;

@end
