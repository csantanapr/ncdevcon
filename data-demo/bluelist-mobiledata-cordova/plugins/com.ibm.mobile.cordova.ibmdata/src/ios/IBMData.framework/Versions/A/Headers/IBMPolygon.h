//-------------------------------------------------------------------------------
// IBM Confidential OCO Source Materials
// XXXX-XXX Copyright IBM Corp. 2014
// The source code for this program is not published or otherwise
// divested of its trade secrets, irrespective of what has
// been deposited with the U.S. Copyright Office.
//-------------------------------------------------------------------------------
//
//  IBMPolygon.h
//  IBMData iOS SDK

#import "IBMGeometry.h"
@class IBMPosition;
@class IBMLinearRing;

/**
 * IBMPolygon corresponds to a GeoJSON Polygon object.
 *
 * The IBMPolygon class is a provisional API.  APIs that are marked provisional are evolving and might change or be removed in future releases.
 *
 * This type of object is defined by a list of one or more GeoJSON LinearRing objects and
 * is represented as follows:
 *
 
 { 
    "type": "Polygon",
    "coordinates": [
                        [ [longitude,latitude,altitude(optional),timestamp(optional)], [longitude,latitude,altitude(optional),timestamp(optional)], [longitude,latitude,altitude(optional),timestamp(optional)], [longitude,latitude,altitude(optional),timestamp(optional)], 
                            [longitude,latitude,altitude(optional),timestamp(optional)] ],
                        [ [longitude,latitude,altitude(optional),timestamp(optional)], [longitude,latitude,altitude(optional),timestamp(optional)], [longitude,latitude,altitude(optional),timestamp(optional)], [longitude,latitude,altitude(optional),timestamp(optional)], [longitude,latitude,altitude(optional),timestamp(optional)] ]
                    ]
 }
 
 * The first LinearRing in the coordinates array represents the exterior ring, and any
 * elements that follow are interior rings.
 *
 * IBMPolygon objects are immutable.
 */
@interface IBMPolygon : NSObject  <IBMGeometry>

/**
 * The array of IBMLinearRing objects that makes up this Polygon. The first IBMLinearRing in this array represents the
 * exterior ring and all subsequent IBMLinearRing objects represent interior rings. The exterior ring is required. (read only)
 */
@property (nonatomic,readonly) NSArray *linearRings;

/**
 * Initialize an IBMPolygon object with an array of IBMLinearRing objects. The first element of the LinearRing
 * represents the exterior ring and is required to define an IBMPolygon object.
 *
 * At this time, inner rings are not validated for containment within the outer ring, and 
 * triggers are only supported on the outer ring.
 *
 * @param linearRings The array of IBMLinearRing objects that form the IBMPolygon.
 */
- (id) initWithLinearRings:(NSArray *)linearRings;

/**
 * Returns the outer ring of the IBMPolygon.
 *
 * @return (IBMLinearRing *) The outer ring of the IBMPolygon object.
 */
- (IBMLinearRing *) outerRing;

@end

