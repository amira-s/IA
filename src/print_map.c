/*
** asciifun.c for octocat in /home/amira_s/octo/src
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Fri Jan  22 16:23:25 2015 AMIRA Syrine
** Last update Fri Jan  22 16:45:07 2015 AMIRA Syrine
*/

#include "my.h"

void print_map(t_map *map, t_player *player)
{
	int n;
	int m;
	int i;
	int j;

	n = map->h + 1 + player->p_x - player->p_x;
	m = map->w;
	for (i = 0; i < n; i++)
	{
	    for (j = 0; j < m; j++)
	    {
	    	if (map->tab[i][j] == 1)
	    		my_putstr("\033[40m \033[0m");
	    	else if (map->tab[i][j] == 2 || map->tab[i][j] == 3)
	    		my_putstr("\033[107;2;30m.\033[0m");
	    	else if (map->tab[i][j] == 4)
				my_putstr("\033[102m \033[0m");
	    	else if (map->tab[i][j] == 7)
	    		my_putstr("\033[106m \033[0m");
	    	else
				my_putstr("\033[1;107;95m8\033[0m");
	    }
    	my_putstr("\n");
	}
}

void minioctomap(int to_p)
{
	if (to_p == 1)
		my_putstr("\033[40m \033[0m");
	else if (to_p == 2 || to_p == 3)
		my_putstr("\033[107;2;30m.\033[0m");
	else if  (to_p == 4)
		my_putstr("\033[102m \033[0m");
	else if (to_p == 7)
		my_putstr("\033[106m \033[0m");
	else
		my_putstr("\033[1;107;95m8\033[0m");
}

void print_octomap(t_map *map, t_player *player)
{
	int n;
	int m;
	int i;
	int j;

	n = map->h + 1;
	m = map->w;
	for (i = 0; i < n; i++)
	{
	    for (j = 0; j < m; j++)
	    {
	    	if ((i <= (player->p_x + 1) && i >= (player->p_x - 1)) && 
	    		(j <= (player->p_y + 1) && j >= (player->p_y - 1)))
	    		minioctomap(map->tab[i][j]);	
		    else
	    		my_putstr("\033[40m \033[0m");
	    }
	    my_putstr("\n");
	}
}

void print_blindmap(t_map *map, t_player *player)
{
	int n;
	int m;
	int i;
	int j;

	n = map->h + 1 - player->p_x + player->p_x;
	m = map->w;
	for (i = 0; i < n; i++)
	{
	    for (j = 0; j < m; j++)
	    {
			if (map->tab[i][j] == 8)
				my_putstr("\033[1;107;95m8\033[0m");
			else if (map->tab[i][j] == 4)
				my_putstr("\033[102m \033[0m");
			else
				my_putstr("\033[40m \033[0m");
	    }
	    my_putstr("\n");
	}
}
