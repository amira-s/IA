/*
** paths.c for AI in /home/amira_s/src/AI
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Feb 22 09:15:10 2016 AMIRA Syrine
** Last update Fri Mar 04 16:52:33 2016 AMIRA Syrine
*/

#include <stdlib.h>
#include "my.h"

t_vect path_pop(t_path *p)
{
    t_vect v;
    t_vect prev;

    if (p->len <= 0) {
        my_putstr("ERROR: path_pop: empty path (len <= 0)\n");
        return (v);
    }
    prev = p->tab[p->len - 2];
    v = p->tab[p->len - 1];
    p->dist -= vect_dist(v, prev);
    p->len -= 1;
    return (v);
}

void path_push(t_path *p, t_vect v)
{
    t_vect prev;

    prev = p->tab[p->len - 1];
    p->tab[p->len] = v;
    p->dist += vect_dist(v, prev);
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
