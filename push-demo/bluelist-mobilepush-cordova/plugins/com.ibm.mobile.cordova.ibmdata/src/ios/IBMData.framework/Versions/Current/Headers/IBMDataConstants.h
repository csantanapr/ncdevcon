//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------
//
//  IBMDataConstants.h
//  IBMData iOS SDK

#ifdef __cplusplus
#define EXTERN		extern "C"
#else
#define EXTERN	    extern
#endif

/**---------------------------------------------------------------------------------------
 * Notifications
 * ---------------------------------------------------------------------------------------
 */

/** Posted when the save for an IBMDataObject completes.
 The object of the notification is the IBMDataObject that was saved.
 There is no userInfo dictionary.
 */

EXTERN NSString *const IBMDataObjectSaveNotification;
