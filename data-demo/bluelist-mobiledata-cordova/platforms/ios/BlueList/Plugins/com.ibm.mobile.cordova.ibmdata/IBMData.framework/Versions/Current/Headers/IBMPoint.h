//-------------------------------------------------------------------------------
// IBM Confidential OCO Source Materials
// XXXX-XXX Copyright IBM Corp. 2014
// The source code for this program is not published or otherwise
// divested of its trade secrets, irrespective of what has
// been deposited with the U.S. Copyright Office.
//-------------------------------------------------------------------------------
//
//  IBMPoint.h
//  IBMData iOS SDK

#import "IBMGeometry.h"
@class IBMPosition;
@class CLLocation;

/**
 * IBMPoint corresponds to a GeoJSON Point object.
 *
 * The IBMPoint class is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 *
 * This type of object is defined by a single GeoJSON position and is represented as follows:
 *
 
 { 
    "type": "Point", 
    "coordinates": [longitude,latitude,altitude(optional),timestamp(optional)]
 }
 
 *
 * IBMPoint objects are immutable.
 */
@interface IBMPoint : NSObject <IBMGeometry>

/**
 * The Position object that makes up this point (read only). 
 */
@property (nonatomic,readonly) IBMPosition *position;

/**
 * Initialize an IBMPoint object with specified latitude and longitude.
 *
 * @param latitude The point object's latitude value, as a double
 * @param longitude The point object's longitude value, as a double
 */
- (id)initWithLatitude:(double)latitude longitude:(double)longitude;
/**
 * Initialize an IMBPoint object with an IBMPosition object
 *
 * @param position The position object used to define the point
 */
- (id)initWithPosition:(IBMPosition *)position;
/**
 * Initialize an IMBPoint object with a CLLocation object
 *
 * @param location The CLLocation object used to define the point
 */
- (id)initWithLocation:(CLLocation *)location;

@end
