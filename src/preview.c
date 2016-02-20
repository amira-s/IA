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

void preview(t_player *player)
{
	t_map *map;
	char *c;
	int i;
	char tmp[2];

	map = malloc(sizeof(t_map));
	for (i = 1; i < 9; i++)
	{
		tmp[0] = (char ) i + 48;
		tmp[1] = '\0';
		c = "Maps/map";
		c = my_strcat(c, tmp);
		map = get_map(c);
		print_map(map, player);
		my_putstr(c);
		my_putstr("\n\n");
	}
	free(c);
	freetab(map);
}
