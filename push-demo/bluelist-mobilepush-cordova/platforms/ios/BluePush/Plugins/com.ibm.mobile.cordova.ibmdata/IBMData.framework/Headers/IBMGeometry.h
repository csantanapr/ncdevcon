//-------------------------------------------------------------------------------
// IBM Confidential OCO Source Materials
// XXXX-XXX Copyright IBM Corp. 2014
// The source code for this program is not published or otherwise
// divested of its trade secrets, irrespective of what has
// been deposited with the U.S. Copyright Office.
//-------------------------------------------------------------------------------
//
//  IBMGeometry.h
//  IBMData iOS SDK

/**
 * TYPESTRING and COORDINATESSTRING are used to build GeoJSON formats of IBMGeometry objects.
 */
#define TYPESTRING @"type"
#define COORDINATESSTRING @"coordinates"

/**
 * IBMGeometry is a protocol that defines common methods to all geometry objects that are GeoJSON compliant.
 *
 * The IBMGeometry protocol is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.

 */
@protocol IBMGeometry <NSObject>

/**
 * Initialize an IBMGeometry compliant object using JSON data that conforms to GeoJSON specifications.
 *
 * @param geoJSON The GeoJSON data used to initialize the IBMGeometry compliant object.
 */
- (id)initWithGeoJSON:(NSDictionary *)geoJSON;

/**
 * Returns a JSON representation of a GeoJSON object.
 *
 * @return (NSDictionary *) A JSON object containing the GeoJSON representation of this geometry.
 */
-(NSDictionary*) geoJSON;

/**
 * Returns a string representing the GeoJSON type of the IBMGeometry compliant object.
 * 
 * @return (NSString *) A string representing the GeoJSON type of this IBMGeometry compliant object.
 */
-(NSString*) type;

@end
