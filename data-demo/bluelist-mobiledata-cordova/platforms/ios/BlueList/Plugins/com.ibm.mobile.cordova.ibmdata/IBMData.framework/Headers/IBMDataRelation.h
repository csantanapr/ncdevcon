//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------
//
//  IBMDataRelation.h
//  IBMData iOS SDK

#import <IBMData/IBMData.h>

@class IBMQuery;

/**
  IBMDataRelation is a container that holds references to IBMDataObjects. Its intended
  use is to express a relationship from one IBMDataObject to some set of other IBMDataObjects.
*/

@interface IBMDataRelation : NSObject

/** Adds object to this relation.

 @param object The object to be added to the relation
 */
- (void)addObject:(IBMDataObject *)object;

/** Removes object from this relation.

 @param object The object to be added to the relation
 */
- (void)removeObject:(IBMDataObject *)object;

/** Returns a query to fetch the objects contained in this relation.

 @return (IBMQuery *) The query for the objects in this relation
 */
- (IBMQuery *)query;

@end
