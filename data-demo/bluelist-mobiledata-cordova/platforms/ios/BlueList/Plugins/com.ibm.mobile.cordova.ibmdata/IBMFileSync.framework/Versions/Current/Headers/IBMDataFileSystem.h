//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import <IBMBluemix/BFTask.h>

@class IBMDataFile;

/**
 *  This represents the data file system.
 *
 * The IBMDataFileSystem class is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 */

@interface IBMDataFileSystem : NSObject

/**---------------------------------------------------------------------------------------
 * @name Creating Files
 * ---------------------------------------------------------------------------------------
 */

/**
 * Creates a file object
 * @param identifier The file unique identifier.
 * @param error  The error that may occur
 * @returns value representing the file.
 */
- (IBMDataFile *)fileWithIdentifier:(NSString*)identifier error:(NSError**)error;

/**
 * Creates a file object
 * @param path This represents the path (with file name) saved on the server.
 * @param error The error that may occur
 * @returns value representing the file.
 */
- (IBMDataFile *)fileWithRelativePath:(NSString*)path error:(NSError**)error;

/**
 * Creates a file object
 * @param path  This represents the path (with file name) saved on the server.
 * @param data  array of bytes containing the file data.
 * @param error The error that may occur
 * @returns value representing the file.
 */
- (IBMDataFile *)fileWithRelativePath:(NSString*)path fromData:(NSData*)data error:(NSError**)error;

/**
 * Creates a file object
 * @param path This represents the path (with file name) saved on the server.
 * @param fromPath  The existing file containing the file data.
 * @param error The error that may occur
 * @returns value representing the file.
 */
- (IBMDataFile *)fileWithRelativePath:(NSString*)path fromFile:(NSString*)fromPath error:(NSError**)error;

/**---------------------------------------------------------------------------------------
 * @name Discovering Directory Contents
 * ---------------------------------------------------------------------------------------
 */

/**
 * Returns a list of paths for files available in the local filesystem.
 *
 * @param error The error that may occur
 * @returns list of local files.
 */
- (NSArray*)localFiles:(NSError**)error;

/**
 * Returns a list of paths for all files in the IBMDataFileSystem.
 * @return a BFTask that can be used to retrieve the list of paths
 */
- (BFTask*)cloudFiles;

/**---------------------------------------------------------------------------------------
 * @name Creating Files
 * ---------------------------------------------------------------------------------------
 */

/**
 * Synchronize file in the background
 * @return a BFTask that can be used to determine the results of the synchronization action.
 */
-(BFTask*)sync;

@end
