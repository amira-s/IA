#include "vect.h"

#define ABS(x) ((x) > 0 ? (x) : -(x))

t_vect vect_abs(t_vect v)
{
    return (vect(ABS(v.x), ABS(v.y)));
}

int vect_length(t_vect v)
{
    return (ABS(v.x) + ABS(v.y));
}

int vect_dist(t_vect v1, t_vect v2)
{
    return (ABS(v1.x - v2.x) + ABS(v1.y - v2.y));
}
