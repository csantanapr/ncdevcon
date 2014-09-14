//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

/**
 * Storage Provider client event interface.
 *
 */
@protocol IBMDataStorageProvider;

@protocol IBMDataStorageProviderConnectCallback<NSObject>

/**
 * Storage Provider connected successfully. From this point on the client application is free to connect to the Cloud Manager.
 * @param provider IBMDataStorageProvider connected.
 * @param params NSDictionary containing the parameters passed during connection.
 */
-(void)onStorageConnected:(id<IBMDataStorageProvider>)provider
                   params:(NSDictionary *)params;
/**
 * Invoked if there is any error during the connect process. The Storage Provider won't connect if this event is invoked.
 * @param provider IBMDataStorageProvider connected.
 * @param error NSError.
 */
-(void)onStorageConnectError:(id<IBMDataStorageProvider>)provider error:(NSError*)error;
/**
 * Invoked after a successful disconnect.
 * @param provider IBMDataStorageProvider disconnected.
 */
-(void)onStorageDisconnected:(id<IBMDataStorageProvider>)provider;
/**
 * Invoked if there is any error during the disconnect process. The client application should check if the Storage Provider
 * is still connected.
 * @param provider IBMDataStorageProvider with error.
 * @param error NSError.
 */
-(void)onStorageDisconnectError:(id<IBMDataStorageProvider>)provider error:(NSError*)error;

@end
