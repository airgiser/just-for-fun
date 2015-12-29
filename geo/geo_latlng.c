//
//  geo_latlng.c
//
//  Created by huweijun
//  Copyright (c) 2015 airgiser. All rights reserved.
//

#include "geo_latlng.h"
#include <math.h>

#define EARTH_RADIUS 6371000


geo_latlng geo_latlng_make(float latitude, float longitude)
{
    geo_latlng coord;
    coord.latitude = latitude;
    coord.longitude = longitude;
    return coord;
}

static inline double geo_to_radians(double degree)
{
    return degree * M_PI / 180;
}

static inline double geo_to_degrees(double radians)
{
    return radians * 180 / M_PI;
}

/*
 static inline float geo_calculate_distance_haversine(float lat1, float lon1, float lat2, float lon2)
 {
 double lat1_radians = geo_to_radians(lat1);
 double lat2_radians = geo_to_radians(lat2);
 double delta_lat = geo_to_radians(lat2 - lat1);
 double delta_lon = geo_to_radians(lon2 - lon1);
 
 // haversine formula
 // a = sin²(Δφ/2) + cos φ1 ⋅ cos φ2 ⋅ sin²(Δλ/2)
 // c = 2 ⋅ atan2( √a, √(1−a) ) --> c = 2 ⋅ asin(√a)
 // d = R ⋅ c
 double a = sin(delta_lat/2) * sin(delta_lat/2) + cos(lat1_radians) * cos(lat2_radians) * sin(delta_lon/2) * sin(delta_lon/2);
 double c = 2 * asin(sqrt(a));
 return c * EARTH_RADIUS;
 }
 
 static inline float geo_calculate_distance_spherical_cosines(float lat1, float lon1, float lat2, float lon2)
 {
 double lat1_radians = geo_to_radians(lat1);
 double lat2_radians = geo_to_radians(lat2);
 double delta_lon = geo_to_radians(lon2 - lon1);
 
 // spherical law of cosines formula
 // d = acos( sin φ1 ⋅ sin φ2 + cos φ1 ⋅ cos φ2 ⋅ cos Δλ ) ⋅ R
 return EARTH_RADIUS * acos(sin(lat1_radians)*sin(lat2_radians) + cos(lat1_radians)*cos(lat2_radians)*cos(delta_lon));
 }
 */

static inline float geo_calculate_distance_equirectangular(float lat1, float lon1, float lat2, float lon2)
{
    double lat1_radians = geo_to_radians(lat1);
    double lat2_radians = geo_to_radians(lat2);
    double lon1_radians = geo_to_radians(lon1);
    double lon2_radians = geo_to_radians(lon2);
    
    // equirectangular approximation
    // x = Δλ ⋅ cos φm
    // y = Δφ
    //          _______
    // d = R ⋅ √x² + y²
    double x = (lon2_radians - lon1_radians) * cos((lat1_radians + lat2_radians) / 2);
    double y = (lat2_radians - lat1_radians);
    return sqrt(x*x + y*y) * EARTH_RADIUS;
}

static inline float geo_calculate_bearing(float lat1, float lon1, float lat2, float lon2)
{
    double lat1_radians = geo_to_radians(lat1);
    double lat2_radians = geo_to_radians(lat2);
    double delta_lon = geo_to_radians(lon2 - lon1);
    
    // θ = atan2( sin Δλ ⋅ cos φ2 , cos φ1 ⋅ sin φ2 − sin φ1 ⋅ cos φ2 ⋅ cos Δλ )
    double y = sin(delta_lon) * cos(lat2_radians);
    double x = cos(lat1_radians)*sin(lat2_radians) - sin(lat1_radians)*cos(lat2_radians)*cos(delta_lon);
    double theta = atan2(y, x);
    double degrees = geo_to_degrees(theta);
    return fmod(degrees + 360, 360);
}

float geo_latlng_get_distance(geo_latlng pt1, geo_latlng pt2)
{
    return geo_calculate_distance_equirectangular(pt1.latitude, pt1.longitude, pt2.latitude, pt2.longitude);
}

float geo_latlng_get_bearing(geo_latlng pt1, geo_latlng pt2)
{
    return geo_calculate_bearing(pt1.latitude, pt1.longitude, pt2.latitude, pt2.longitude);
}

geo_latlng geo_latlng_get_destination(geo_latlng start_point, float bearing, float distance)
{
    double lat1 = geo_to_radians(start_point.latitude);
    double lon1 = geo_to_radians(start_point.longitude);
    double b = geo_to_radians(bearing);
    
    // φ2 = asin( sin φ1 ⋅ cos δ + cos φ1 ⋅ sin δ ⋅ cos θ )
    // λ2 = λ1 + atan2( sin θ ⋅ sin δ ⋅ cos φ1, cos δ − sin φ1 ⋅ sin φ2 )
    double ddR = distance/EARTH_RADIUS;
    double lat2 = asin(sin(lat1)*cos(ddR) + cos(lat1)*sin(ddR)*cos(b));
    double lon2 = lon1 + atan2(sin(b)*sin(ddR)*cos(lat1), cos(ddR)-sin(lat1)*sin(lat2));
    return geo_latlng_make(geo_to_degrees(lat2), geo_to_degrees(lon2));
}
