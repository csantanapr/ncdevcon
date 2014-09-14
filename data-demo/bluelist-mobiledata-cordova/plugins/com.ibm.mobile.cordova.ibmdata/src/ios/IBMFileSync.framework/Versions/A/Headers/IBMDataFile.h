//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import <IBMBluemix/BFTask.h>

enum IBMDATAFILE_REQUEST_POLICY {
	IBMDataFileRequestReturnCachedIfExists  = 0,
    IBMDataFileRequestReturnCloud           = 1
};

/** Representation of a file stored in the Mobile File service.
 *
 * The IBMDataFile class is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 *
 * IBMDataFile objects can be downloaded and synchronized with the mobile device.
 */

@interface IBMDataFile : NSObject

/**---------------------------------------------------------------------------------------
 * @name Creating Files
 * ---------------------------------------------------------------------------------------
 */

/**
 * Creates a new empty file object.
 *
 * @param path  The path for the file relative to the managed directory.
 * @param errorPtr If an error occurs, upon return contains an NSError object that describes the problem.
 * @returns value representing the file.
 */
+ (IBMDataFile *)fileWithRelativePath:(NSString *)path error:(NSError **)errorPtr;

/**
 * Creates a new file object containing the specified data.
 *
 * @param path  The path for the file relative to the managed directory.
 * @param data  The initial contents of the file.
 * @param errorPtr If an error occurs, upon return contains an NSError object that describes the problem.
 * @returns value representing the file.
 */
+ (IBMDataFile *)fileWithRelativePath:(NSString *)path withContents:(NSData *)data error:(NSError **)errorPtr;

/**---------------------------------------------------------------------------------------
 * @name Getting and Setting File Attributes
 * ---------------------------------------------------------------------------------------
 */

/**
 * The unique identifier for the file. (read-only)
 */
@property (nonatomic,strong,readonly) NSString* identifier;

/**
 * The file path relative to the managed directory. (read-only)
 */
@property (nonatomic,strong,readonly) NSString* path;

/**
 * The full file path. (read-only)
 */
@property (nonatomic,strong,readonly) NSString* fullPath;

/**
 * The date/time this file was created. (read-only)
 */
@property (nonatomic,readonly)		NSDate *createdAt;

/**
 * The date/time this file was last modified. (read-only)
 */
@property (nonatomic,readonly)		NSDate *modifiedAt;

/**
 * The number of bytes in the file. (read-only)
 */
@property (nonatomic,readonly)		NSUInteger length;

/**
 * The mime content type of the file.
 *
 * The contentType may be used to determine how to display the file in web interfaces.
 */
@property (nonatomic,strong) NSString* contentType;

/**
 * Returns the file contents.
 *
 * @param errorPtr If a failure occurs obtaining the file contents, an NSError object that describes the problem.
 * @returns file contents.
 */
- (NSData *)contents:(NSError**)errorPtr;

/**---------------------------------------------------------------------------------------
 * @name Saving a File
 * ---------------------------------------------------------------------------------------
 */

/**
 * Save the file in the background
 * @return the BFTask that can be used to retrieve the result once save completes
 */
- (BFTask*)save;

/**---------------------------------------------------------------------------------------
 * @name Fetching a File
 * ---------------------------------------------------------------------------------------
 */

/**
 * Fetch the file in the background
 * @param policy The request policy
 * @return the BFTask that can be used to retrieve the result once fetch completes
 */
- (BFTask*)fetch:(enum IBMDATAFILE_REQUEST_POLICY)policy;

/**---------------------------------------------------------------------------------------
 * @name Removing a File
 * ---------------------------------------------------------------------------------------
 */

/**
 * Deletes a file in the background
 * @return the BFTask that can be used to retrieve the result once delete completes
 */
- (BFTask*)delete;

@end
