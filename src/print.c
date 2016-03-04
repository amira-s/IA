/*
** print.c for AI in /home/amira_s/src/AI
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Feb 22 09:15:10 2016 AMIRA Syrine
** Last update Fri Mar 04 16:52:33 2016 AMIRA Syrine
*/

#include "my.h"

void print_path(t_path *path)
{
    t_vect *v;
    t_vect *vects;
    int i;

    for (i = 0, vects = path->tab; i < path->len; i++)
    {
        v = vects + i;
        my_putstr(FG_YELLOW"{"COLOR_RESET);
        my_put_nbr(v->x);
        my_putstr(FG_YELLOW","COLOR_RESET);
        my_put_nbr(v->y);
        my_putstr(FG_YELLOW"} "COLOR_RESET);
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

    my_putstr(BG_WHITE""FG_RED" Solution ");
    my_put_nbr(index);
    my_putstr(" ("FG_BLUE);
    my_put_nbr(movesc);
    put_str_mb_plural(FG_RED" move", movesc);
    my_putstr(") "COLOR_RESET"\n");
    print_path(path);
    noop(_);
}

void print_solutions(t_da *solutions)
{
    da_foreach(solutions, _print_solution);
}

#ifdef DEBUG
void print_resrc_tab(t_map *map)
{
    int i;

    my_putstr("-----------\n");
    for (i = 0; i < map->resrc.len; i++)
    {
        print_resrc(map, i);
    }
    my_putstr("-----------\n");
}
#endif /* DEBUG */

void    print_resrc(t_map *map, int i)
{
    my_putstr("resrc ");
    my_put_nbr(i);
    my_putstr(": (");
    my_put_nbr(map->resrc.tab[i].coord.x);
    my_putstr(", ");
    my_put_nbr(map->resrc.tab[i].coord.y);
    my_putstr(")\n");
}
