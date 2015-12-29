//
//  geo_region.c
//
//  Created by huweijun
//  Copyright (c) 2015 airgiser. All rights reserved.
//

#include "geo_region.h"


geo_region geo_region_make(float min_x, float min_y, float max_x, float max_y)
{
    geo_region region;
    region.min_x = min_x;
    region.min_y = min_y;
    region.max_x = max_x;
    region.max_y = max_y;
    return region;
}

float geo_region_get_width(geo_region region)
{
    return region.max_x - region.min_x;
}

float geo_region_get_height(geo_region region)
{
    return region.max_y - region.min_y;
}

int geo_region_contains_region(geo_region region1, geo_region region2)
{
    return (region2.min_x >= region1.min_x) && (region2.min_y >= region1.min_y)
    && (region2.max_x <= region1.max_x) && (region2.max_y <= region1.max_y);
}

int geo_region_contains_point(geo_region region, geo_latlng point)
{
    return point.latitude >= region.min_y && point.latitude <= region.max_y
    && point.longitude >= region.min_x && point.longitude <= region.max_x;
}

int geo_region_intersects_region(geo_region region1, geo_region region2)
{
    if (region2.min_x > region1.max_x) return 0;
    if (region2.max_x < region1.min_x) return 0;
    if (region2.min_y > region1.max_y) return 0;
    if (region2.max_y < region1.min_y) return 0;
    return 1;
}
