#include <stdlib.h>
#include <stdio.h>
#include "pool.h"

typedef struct point {
    float x;
    float y;
}Point;

int main() {
    MemPool *pool = mempool_create(sizeof(Point), 1024, 256);
    // TODO;
    Point *pt = (Point*)mempool_alloc(pool);
    mempool_destroy(pool);
    return 0;
}
