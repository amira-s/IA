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

void    path_new(t_path *path, t_map *map)
{
    path->tab = malloc(100 * sizeof(t_vect));
    path->tab[0].x = map->start.x;
    path->tab[0].y = map->start.y;
    path->dist = 0;
    path->len = 1;
}

t_path      *path_copy(t_path *path)
{
    t_path *newpath;
    int tab_size;
    int i;

    newpath = malloc(sizeof(t_path));
    newpath->dist = path->dist;
    newpath->len = path->len;
    tab_size = (path->len + 100) * sizeof(t_vect);

    if ((newpath->tab = malloc(tab_size)) == NULL)
        return (trace(NULL, "path_copy: malloc failed"));



    for (i = 0; i <  path->len; i++)
        newpath->tab[i] = path->tab[i]; 
    return (newpath);
}
