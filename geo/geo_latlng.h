//
//  geo_latlng.h
//
//  Created by huweijun
//  Copyright (c) 2015 airgiser. All rights reserved.
//

#ifndef GEO_LATLNG_H__
#define GEO_LATLNG_H__

#include <stdio.h>


/**
 *  coordinate of a point.
 */
typedef struct geo_latlng {
    float latitude;
    float longitude;
}geo_latlng;


/**
 *  make a point from (latitude, longitude).
 *
 *  @param latitude  latitude of the point.
 *  @param longitude longitude of the point.
 *
 *  @return a point of geo_latlng
 */
geo_latlng geo_latlng_make(float latitude, float longitude);

/**
 *  calculate the great-circle distance between two points(over the earth's surface).
 *
 *  @param pt1 coordinate of the first point.
 *  @param pt2 coordinate of the second point.
 *
 *  @return distance(in meters) between the given two points.
 */
float geo_latlng_get_distance(geo_latlng pt1, geo_latlng pt2);

/**
 *  calculate the initial bearing from the start point to the end point.
 *
 *  @param pt1 coordinate of the start point
 *  @param pt2 coordinate of the end point
 *
 *  @return bearing(degrees) from the start point to the end point.
 */
float geo_latlng_get_bearing(geo_latlng pt1, geo_latlng pt2);

/**
 *  given a start point, initial bearing, and distance, calculate the destination point.
 *
 *  @param start_point   the start point
 *  @param bearing       the initial bearing
 *  @param distance      distance from the start point
 *
 *  @return the destination point along great-circle given distance and bearing from start point
 */
geo_latlng geo_latlng_get_destination(geo_latlng start_point, float bearing, float distance);

#endif /* GEO_LATLNG_H__ */
