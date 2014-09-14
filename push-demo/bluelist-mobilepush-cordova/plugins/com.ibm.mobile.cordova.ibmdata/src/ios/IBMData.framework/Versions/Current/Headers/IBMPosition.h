//-------------------------------------------------------------------------------
// IBM Confidential OCO Source Materials
// XXXX-XXX Copyright IBM Corp. 2014
// The source code for this program is not published or otherwise
// divested of its trade secrets, irrespective of what has
// been deposited with the U.S. Copyright Office.
//-------------------------------------------------------------------------------
//
//  IBMCoordinate.h
//  IBMData iOS SDK

@class CLLocation;

/**
 * IBMPosition corresponds to a GeoJSON Position object and is a 
 * fundamental component of GeoJSON compliant objects.
 * 
 * The IBMPosition class is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 *
 * IBMPosition objects are immutable.
 */
@interface IBMPosition : NSObject

/**
 * The location object, which describes the physical location of the position (read only).
 */
@property (nonatomic,readonly) CLLocation *location;

/**
 * Initialize an IBMPosition object using a JSON array that conforms to GeoJSON 
 * specifications for position objects.
 * 
 * The order of values in the array must follow this order: [longitude,latitude,altitude,timestamp]
 * where altitude and timestamp are optional additional elements. Altitude must be provided if timestamp
 * is provided. 
 * 
 * Longitude, latitude, and altitude are represented as double values and timestamp is an NSDate object.
 *
 * @param jsonArray The JSON array of data points that represents a GeoJSON position object.
 */
- (id)initWithJSONArray:(NSArray *)jsonArray;
/**
 * Initialize an IBMPosition object with specified latitude and longitude.
 *
 * @param latitude The position object's latitude value, as a double
 * @param longitude The position object's longitude value, as a double
 */
- (id)initWithLatitude:(double)latitude longitude:(double)longitude;
/**
 * Initialize an IBMPosition object with a CLLocation object.
 *
 * @param location The CLLocation object to build the position with
 */
- (id)initWithLocation:(CLLocation *)location;
/**
 * Returns a JSON array that represents a GeoJSON position object. This will take the form 
 *
 * [longitude,latitude,altitude(optional),timestamp(optional)]
 *
 * Where timestamp complies with ISO 8061 JSON date formatting.
 *
 * @return (NSArray *) A JSON array that represents the GeoJSON position.
 */
- (NSArray*) geoJSON;

@end
