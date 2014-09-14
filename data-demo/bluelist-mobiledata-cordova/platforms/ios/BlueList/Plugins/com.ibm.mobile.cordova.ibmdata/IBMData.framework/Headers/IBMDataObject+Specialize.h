//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------
//
//  IBMDataObject+Specialize.h
//  IBMData iOS SDK

#import <IBMData/IBMDataObject.h>

@class IBMQuery;

//////////////////////////////////////////////////////////////////////////////////////////
//
//	IBMDataObjectSpecialization
//

/**
 The IBMDataObjectSpecialization protocol groups methods that should be implemented by a class that will be registered as a specialization using the IBMDataObject registerSpecialization class method.

 The application can register a specialization the IBMDataObject class, which creates a subclass of IBMDataObject with a specific classname attribute.  Any property of the specialization can be stored in the underlying IBMDataObject by simply designating the property as dynamic in the implementation of the specialization.  The base class is responsible for performing the base actions (create, read, update, delete) against the object.  This includes caching, conflict resolution and communication with the backend server.

 The specialized class allows the developer to define a “schema” for these specialized objects by defining properties with different types.  These properties may be manipulated directly and the specialization support will handle mapping these variables into the underlying Mobile Data object. For example, a specialization class might declare a property of type float with a name of “price”.   The developer can then refer to “object.price”.

 Classes that want to specialize the IBMDataObject must inherit from IBMDataObject and conform to this protocol.
 The IBMDataObject+Specialize category implements all the required methods except for the dataClassName method.
*/
@protocol IBMDataObjectSpecialization

/**---------------------------------------------------------------------------------------
 * @name Registering a Specialization
 * ---------------------------------------------------------------------------------------
 */

/** Registers the class (the receiver) with the Mobile Data service as a specialized class */
+ (void)registerSpecialization;

/**---------------------------------------------------------------------------------------
 * @name Getting the classname
 * ---------------------------------------------------------------------------------------
 */

/** Returns the classname for the specialized class. */
+ (NSString *)dataClassName;

/**---------------------------------------------------------------------------------------
 * @name Creating Objects
 * ---------------------------------------------------------------------------------------
 */

/** Creates and returns an object of the specialized class.

 @return The created object
 */
+ (instancetype)object;

/** Initialize a new object (the receiver) immediately after memory for it has been allocated.

 This method must invoke the designated initializer of IBMDataObject, initWithClass:, specifying the same classname
 as returned by the dataClassName class method.
 */
- (instancetype)init;

/**---------------------------------------------------------------------------------------
 * @name Creating a Query
 * ---------------------------------------------------------------------------------------
 */

/** Returns a query to fetch all objects of the specialized class by classname

 @return (IBMQuery *) The query for all objects of the specialized class
 */
+ (IBMQuery *)query;

@end

/** This category implements most of the required methods for classes that specialize IBMDataObject.
 */

@interface IBMDataObject(Specialize)

/**---------------------------------------------------------------------------------------
 * @name Registering a Specialization
 * ---------------------------------------------------------------------------------------
 */

/** Registers the class (the receiver) with the Mobile Data service as a specialized class */
+ (void)registerSpecialization;

/**---------------------------------------------------------------------------------------
 * @name Creating Objects
 * ---------------------------------------------------------------------------------------
 */

/** Creates and returns an object of the specialized class.

 @return The created object
 */
+ (instancetype)object;

/** Initialize a new object (the receiver) immediately after memory for it has been allocated. */
- (instancetype)init;

/**---------------------------------------------------------------------------------------
 * @name Creating a Query
 * ---------------------------------------------------------------------------------------
 */

/** Returns a query to fetch all objects of the specialized class by classname

 @return (IBMQuery *) The query for all objects of the specialized class
 */
+ (IBMQuery *)query;

@end
