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

void print_map(t_map map)
{
	int i;
	int j;

	my_putstr("\033[1;1H\033[2J");
	for (i = 0; i < map.h; i++)
	{
	    for (j = 0; j < map.w; j++)
	    {
	    	if (map.tab[i][j] == '#')
	    		my_putstr("\033[42m \033[0m");
	    	else if (map.tab[i][j] == ' ')
	    		my_putstr("\033[107;2;30m \033[0m");
	    	else if (map.tab[i][j] == '+')
	    		my_putstr("\033[46;36m \033[0m");
	    	else if (map.tab[i][j] == '-')
				my_putstr("\033[1;107;95m \033[0m");
	    	else
				my_putstr("\033[1;105;95m \033[0m");
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

int lte(int a, int b) {
	return (a <= b);
}

int gte(int a, int b) {
	return (a >= b);
}

void init_cond(int(**comp)(int, int), int *inc1, int a, int b)
{
	if (a < b)
	{
		*comp = lte;
		*inc1 = 1;
	}
	else
	{
		*comp = gte;
		*inc1 = -1;
	}
}

void move(t_map map, t_path *path, t_da *solutions)
{
	int i;
	int j;
	int k;
	int(*comp)(int, int);
	int inc1;

	for (j = 0; j < path->len; j++)
	{
		i = map.start.x;
		k = map.start.y;
		init_cond(&comp, &inc1, i, path->tab[j].x);
		for (;comp(i, path->tab[j].x); i += inc1)
		{
			usleep(DELAY);
			swap(&map, i, map.start.y);
			print_map(map);
		}
		init_cond(&comp, &inc1, k, path->tab[j].y);	
		for (;comp(k, path->tab[j].y); k += inc1)
		{
			usleep(DELAY);
			swap(&map, map.start.x, k);
			print_map(map);
		}
	}
	print_solutions(solutions);
	my_putstr("OK\n");
}
