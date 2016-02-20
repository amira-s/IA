#include "my.h"

void print_path(t_path *path)
{
    t_vect *v;
    t_vect *vects;
    int i;

    for (i = 0, vects = path->tab; i < path->len; i++)
    {
        v = vects + i;
        my_putstr("{");
        my_put_nbr(v->x);
        my_putstr(",");
        my_put_nbr(v->y);
        my_putstr("} ");
    }
    my_putstr("\n");
}

void put_str_mb_plural(char *str, int count)
{
    my_putstr(str);
    if (count > 1)
        my_putstr("s");
}

void _print_solution(void *solution, int index, void* _)
{
    t_path* path;
    int movesc;
    
    path = (t_path*)solution;
    movesc = path->dist;

    my_putstr("== Solution ");
    my_put_nbr(index);
    my_putstr(" (");
    my_put_nbr(movesc);
    put_str_mb_plural(" move", movesc);
    my_putstr(")\n");
    print_path(path);
    noop(_);
}

void print_solutions(t_da *solutions)
{
    da_foreach(solutions, _print_solution);
}