#include <stdlib.h>
#include "my.h"

t_vect path_pop(t_path *p)
{
    t_vect v;

    if (p->len <= 0) {
        my_putstr("ERROR: path_pop: empty path (len <= 0)\n");
        return (v);
    }

    v = p->tab[p->len - 1];
    p->dist -= v.x + v.y;
    p->len -= 1;
    return (v);
}

void path_push(t_path *p, t_vect v)
{
    p->tab[p->len] = v;
    p->dist += v.x + v.y;
    p->len += 1;
}