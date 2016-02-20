#include "vect.h"

t_vect vect(int x, int y)
{
    t_vect v;
    v.x = x;
    v.y = y;
    return (v);
}

t_vect vect_add(t_vect v1, t_vect v2)
{
    return (vect(v1.x + v2.x, v1.y + v2.y));
}

t_vect vect_sub(t_vect v1, t_vect v2)
{
    return (vect(v1.x - v2.x, v1.y - v2.y));
}

t_vect vect_mult(t_vect v1, t_vect v2)
{
    return (vect(v1.x * v2.x, v1.y * v2.y));
}

t_vect vect_div(t_vect v1, t_vect v2)
{
    return (vect(v1.x / v2.x, v1.y / v2.y));
}
