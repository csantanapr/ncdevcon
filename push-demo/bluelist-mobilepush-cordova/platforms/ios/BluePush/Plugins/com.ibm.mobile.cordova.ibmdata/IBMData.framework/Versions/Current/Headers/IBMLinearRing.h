//-------------------------------------------------------------------------------
// IBM Confidential OCO Source Materials
// XXXX-XXX Copyright IBM Corp. 2014
// The source code for this program is not published or otherwise
// divested of its trade secrets, irrespective of what has
// been deposited with the U.S. Copyright Office.
//-------------------------------------------------------------------------------
//
//  IBMRing.h
//  IBMData iOS SDK

#import "IBMLineString.h"
@class IBMPosition;

/**
 * IBMLinearRing corresponds to a GeoJSON LinearRing object.
 *
 * The IBMLinearRing class is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 *
 * An IBMLinearRing object represents a closed IBMLineString object of 4 or more positions.
 * For the LineString to be closed, the first position and last position must refer to equivalent points.
 * 
 * A LinearRing is not a top-level GeoJSON object, but is used in the definition of a GeoJSON 
 * Polygon object.
 *
 * IBMLinearRing objects are immutable.
 */
@interface IBMLinearRing : IBMLineString

/**
 * Initialize an IBMLinearRing object with an array of IBMPosition objects.
 *
 * @param positions The array of IBMPosition objects that form the LinearRing.
 */
-(id) initWithPositionArray:(NSArray *)positions;
/**
 * Initialize an IBMLinearRing object with an array of GeoJSON positions.
 *
 * The order of values in each GeoJSON position array must follow this order: [longitude,latitude,altitude,timestamp]
 * where altitude and timestamp are optional additional elements. Altitude must be provided if timestamp
 * is provided.
 *
 * Longitude, latitude, and altitude are represented as double values and timestamp is an NSDate object.
 *
 * @param jsonArray The array of GeoJSON positions that form the LinearRing.
 */
-(id) initWithJSONArray:(NSArray *)jsonArray;

@end
