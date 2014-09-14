//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import <IBMBluemix/BFTask.h>

/**
 * Live Synchronization parameter key.
 */
extern NSString* const IBMFileLiveSyncEnableKey;
/**
 * UserId connect parameter key.
 */
extern NSString* const IBMUseridKey;
/**
 * File change notification name.
 */
extern NSString* const IBMFilesDiidChangeNotification;
/**
 * File change reason.
 */
extern NSString* const IBMFilesChangeReasonKey;
/**
 * File change key.
 */
extern NSString* const IBMFilesChangedFilesKey;

/**
 * An enumeration for file notification values
 */
enum {
    IBMFileServerAdd,            /**< File added */
    IBMFileServerChange,         /**< File changed */
    IBMFileServerRemove          /**< File removed */
};

@class IBMDataClientManager;
@class IBMDataFileSystem;

/**
 * IBMDataClientManagerDelegate protocol.
 *
 * The IBMDataClientManagerDelegate protocol is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 */

@protocol IBMDataClientManagerDelegate

/**---------------------------------------------------------------------------------------
 * @name Handle events in file sync operations
 * ---------------------------------------------------------------------------------------
 */

/**
 * Invoked if there is an error while the File Service is running.
 *
 * @param manager The IBMDataClientManager for this delegate.
 * @param error NSError.
 */
- (void)dataClientManager:(IBMDataClientManager *)manager onError:(NSError *)error;

@end

/**
 * IBMDataClientManager singleton interface.
 *
 * The IBMDataClientManager class is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 *
 * The DataClientManager is responsible for keeping the files in synch with the Cloud automatically at all times.
 * <p>
 * The client application needs only to connect and use the normal file IO routines as if the files were being read/written locally.
 * The DataClientManager will upload/download the files asynchronously when they change.
 * <p>
 * During the initial connection process the local files are synchronized with the Cloud.
 * The client application will receive events of file activities, so that it can update its UI, but it won't have control over the
 * synchronization process.
 */
@interface IBMDataClientManager : NSObject

/**
 * IBMDataClientManager singleton factory method
 * @returns newly created IBMDataClientManager if doesn't exist or already created one.
 */
+ (IBMDataClientManager*)sharedManager;

/**
 * The IBMDtaFileSystem managed by the IBMDataClientManager (read-only).
 */
@property (nonatomic, strong, readonly) IBMDataFileSystem *fileSystem;

/**
 * The path to the local directory managed by the IBMDataClientManager (read-only).
 *
 * @returns File directory.
 */
@property (nonatomic, strong, readonly) NSString* appDirectory;

/**
 * The IBMDataClientManagerDelegate for this IBMDataClientManager.
 *
 * It should be set before the connect method in order to receive all events.
 */
@property (nonatomic, weak) id<IBMDataClientManagerDelegate> delegate;

/**
 * Initiates a connection to the File Service.
 *
 * @param parameters Key/Value pairs
 * @return a BFTask that can be used to retrieve the result once connect completes
 */
- (BFTask*)connect:(NSDictionary*)parameters;

/**
 * Disconnects the File Service.
 *
 * @return a BFTask that can be used to retrieve the result once connect completes
 */
- (BFTask*)disconnect;

/**
 * Indicates if the File Service is connected.
 *
 * @returns boolean value indicating if the File Service is connected.
 */
- (BOOL)connected;

@end
