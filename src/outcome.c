/*
** fjkdh for octocat in /home/amira_s/octo/src
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Fri Jan  22 16:23:25 2015 AMIRA Syrine
** Last update Fri Jan  22 16:45:07 2015 AMIRA Syrine
*/

#include "my.h"
#include <unistd.h>

#define DELAY 100000

#define TERM_CLEAR_SIGNAL "\033[1;1H\033[2J"

void init_cond(int(**comp)(int, int), int *inc1, int a, int b);

void print_map(t_map *map)
{
	int i;
	int j;
	my_putstr(TERM_CLEAR_SIGNAL);
	for (i = 0; i < map->h; i++)
	{
	    for (j = 0; j < map->w; j++)
	    {
	    	if (map->tab[i][j] == '#')
	    		my_putstr(PRINTABLE_EXIT);
	    	else if (map->tab[i][j] == ' ')
	    		my_putstr(PRINTABLE_SPACE);
	    	else if (map->tab[i][j] == '+')
	    		my_putstr(PRINTABLE_RESOURCE);
	    	else if (map->tab[i][j] == '-')
				my_putstr(PRINTABLE_TRACE);
	    	else
				my_putstr(PRINTABLE_PLAYER);
	    }
    	my_putstr("\n");
	}
}

void swap(t_map *map, int i, int j)
{
	map->tab[map->start.x][map->start.y] = '-';
	map->tab[i][j] = '@';
	map->start = vect(i, j);
}

#define PRINT_MAP_AT(map, x, y) \
do { \
    usleep(DELAY); \
    swap(map, x, y); \
    print_map(map); \
} while(0);

void move(t_map *orig_map, t_path *path)
{
    int i;
    int j;
    int k;
    int(*comp)(int, int);
    int inc1;
    t_map *map;

    map = copy_map(orig_map);
    for (j = 0; j < path->len; j++)
    {
        i = map->start.x;
        k = map->start.y;
        init_cond(&comp, &inc1, i, path->tab[j].x);
        for (;comp(i, path->tab[j].x); i += inc1)
            PRINT_MAP_AT(map, i, map->start.y);
        init_cond(&comp, &inc1, k, path->tab[j].y);	
        for (;comp(k, path->tab[j].y); k += inc1)
            PRINT_MAP_AT(map, map->start.x, k);
    }
    free_map(map);
    my_putstr(TERM_CLEAR_SIGNAL);
}
