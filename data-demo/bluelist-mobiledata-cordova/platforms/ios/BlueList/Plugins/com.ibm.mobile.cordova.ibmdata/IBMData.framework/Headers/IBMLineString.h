//-------------------------------------------------------------------------------
// IBM Confidential OCO Source Materials
// XXXX-XXX Copyright IBM Corp. 2014
// The source code for this program is not published or otherwise
// divested of its trade secrets, irrespective of what has
// been deposited with the U.S. Copyright Office.
//-------------------------------------------------------------------------------
//
//  IBMLine.h
//  IBMData iOS SDK

#import "IBMGeometry.h"
@class IBMPosition;

/**
 * IBMLineString corresponds to a GeoJSON LineString object.
 *
 * The IBMLineString class is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 *
 * This type of object is defined by a list of two or more GeoJSON positions and is represented as follows:
 *
 
 {
    "type": "LineString",
    "coordinates": [ [longitude,latitude,altitude(optional),timestamp(optional)],[longitude,latitude,altitude(optional),timestamp(optional)] ]
 }
 
 *
 * IBMLineString objects are immutable.
 */
@interface IBMLineString : NSObject <IBMGeometry>

/**
 * The array of position objects that makes up this LineString (read only).
 */
@property (nonatomic,readonly) NSArray *positions;

/**
 * Initialize an IBMLineString object with an array of IBMPosition objects.
 *
 * @param positions The array of IBMPosition objects that form the LineString.
 */
-(id) initWithPositionArray:(NSArray *)positions;

/**
 * Returns the IBMPosition object at a specific index in the LineString
 *
 * @param idx The index of the position to retrieve
 * @return (IBMPosition *) The position with index <code>idx</code> in the array.
 */
- (IBMPosition*) positionAtIndex:(int)idx;
/**
 * Returns a JSON array of GeoJSON position objects. 
 *
 * @return (NSArray *) A JSON array that represents the array of positions that make up the LineString.
 */
-(NSArray*) geoJSONPositionArray;

@end
