//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------
//
//  IBMQuery.h
//  IBMData iOS SDK

#import <IBMData/IBMData.h>

/** The IBMQuery class represents queries for objects stored in the Mobile Data service.
 */

@interface IBMQuery : NSObject

/**---------------------------------------------------------------------------------------
 * @name Getting Query Attributes
 * ---------------------------------------------------------------------------------------
 */

/** @return The className for a queryForClass type query.
 */
@property (nonatomic, readonly) NSString			*className;

/** @return The objectId for a queryForObjectId type query.
 */
@property (nonatomic, readonly) NSString			*objectId;

/**---------------------------------------------------------------------------------------
 * @name Creating Queries
 * ---------------------------------------------------------------------------------------
 */

/** Creates and returns a query that will match against all objects with the specified class name.
 
 @param classname The class name for the objects being sought
 @return (IBMQuery *) query for all objects with a given class name
 */
+(IBMQuery *)queryForClass:(NSString *)classname;

/** Creates and returns a query for a specific object (by object id).
 
 @param objectId The objectId for the object being sought
 @return (IBMQuery *) query for a specific object
 */
+(IBMQuery *)queryForObjectId:(NSString *)objectId;

/**---------------------------------------------------------------------------------------
 * @name Adding a Condition to a Query
 * ---------------------------------------------------------------------------------------
 */

/** Specify an equals condition against one of the fields in the object
 
 The whereKey:equalTo: method is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 
 @param key The name of the attribute to compare against
 @param value The value to compare with the attribute value
 @return void
 @warning For MVP we only support the equals condition but more can be added as needed
 */
- (void)whereKey:(NSString *)key equalTo:(id)value;

/**---------------------------------------------------------------------------------------
 * @name Issuing a Query
 * ---------------------------------------------------------------------------------------
 */

/** Issue the query to the Mobile Data service.
 
 If successful, the result value of the returned BFTask contains a reference to an array
 of objects that match the query conditions.
 
@return The BFTask that can be used to obtain the query results once the query is completed.
 */
- (BFTask*)find;

@end
