//
//  geo_region.h
//
//  Created by huweijun
//  Copyright (c) 2015 airgiser. All rights reserved.
//

#ifndef GEO_REGION_H__
#define GEO_REGION_H__

#include <stdio.h>
#include "geo_latlng.h"


/**
 *  region definition.
 */
typedef struct geo_region {
    float min_x;
    float min_y;
    float max_x;
    float max_y;
}geo_region;


/**
 *  make a region from (minimal x, minimal y, maximal x, maximal y).
 *
 *  @param min_x minimal x coordinate of the region
 *  @param min_y minimal y coordinate of the region
 *  @param max_x maximal x coordinate of the region
 *  @param max_y maximal y coordinate of the region
 *
 *  @return a reigon
 */
geo_region geo_region_make(float min_x, float min_y, float max_x, float max_y);

/**
 *  get width of the region
 *
 *  @param region a region
 *
 *  @return width of the given region
 */
float geo_region_get_width(geo_region region);

/**
 *  get height of the region
 *
 *  @param region a region
 *
 *  @return height of the given region
 */
float geo_region_get_height(geo_region region);

/**
 *  whether region 'region1' contains region 'region2'
 *
 *  @param region1 one of the region
 *  @param region2 another region
 *
 *  @return return 1 if 'region2' is contained in 'region1', 0 otherwise.
 */
int geo_region_contains_region(geo_region region1, geo_region region2);

/**
 *  whether the given point is contained in the region.
 *
 *  @param region  the region
 *  @param point the given point
 *
 *  @return return 1 if the point is contained in the region, 0 otherwise.
 */
int geo_region_contains_point(geo_region region, geo_latlng point);

/**
 *  whether region 'region1' intersects with region 'region2'
 *
 *  @param region1 one of the region
 *  @param region2 another region
 *
 *  @return return 1 if 'region2' is intersects with 'region1', 0 otherwise.
 */
int geo_region_intersects_region(geo_region region1, geo_region region2);

#endif /* GEO_REGION_H__ */
