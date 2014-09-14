//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------
//
//  IBMUser.h
//  IBMData iOS SDK

#import <IBMData/IBMData.h>

/** IBMUser is a specialized object representing an end user.  This class is a subclass of IBMDataObject.
	This class holds information about the user.
 */

@interface IBMUser : IBMDataObject <IBMDataObjectSpecialization>

/**---------------------------------------------------------------------------------------
 * @name Creating User Objects
 * ---------------------------------------------------------------------------------------
 */

/** Returns a newly created user object.
 *
 @return (instancetype) user
 */
+ (instancetype)user;

/**---------------------------------------------------------------------------------------
 * @name Getting and Setting User Attributes
 * ---------------------------------------------------------------------------------------
 */

/** A unique token that identifies an authenticated user.
 */
@property (nonatomic, readonly)	NSString *uuid;

/** Returns the most recent known location of this user.
 *
 * The currentLocation method is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 *
 * @return (CLLocation *) The current or most recently reported location of the user.
 */
- (CLLocation *)currentLocation;

@end
