//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import "IBMDataStorageProviderConnectCallback.h"
#import "IBMDataFile.h"

/**
 * Storage Provider interface. The storage provider is responsible for connecting/disconnecting.
 *
 */
@protocol IBMDataStorageProvider<NSObject>

/**
 * Type identifier of this Storage Provider
 * @returns Type.
 */
@property (strong,readonly) NSString* type;

/**
 * Parameters returned after successful connection
 * @returns Parameters.
 */
@property (strong,readonly) NSDictionary* connectionParameters;

/**
 * Get/Set the storage client event interface. It should be used before the connect method in order to receive all events.
 * However it can be used at any time.
 */
@property (weak) id<IBMDataStorageProviderConnectCallback> connectDelegate;

/**
 * Connects the Storage Provider.
 * It doesn't block. Success or failure will be indicated by the event methods.
 * @param parameters Key/Value pairs - It varies for different storage provider implementations.
 * @param error identified during the initial connection stage, like missing parameters.
 */
-(BOOL)connect:(NSDictionary*)parameters error:(NSError**)error;
/**
 * Indicates if the Storage Provider is connected.
 * @returns boolean value indicating if the Storage Provider is connected.
 */
-(BOOL)connected;

/**
 * Disconnect Storage Provider. 
 */
-(void)disconnect;

@end
