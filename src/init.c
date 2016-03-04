#include "my.h"

#define DEFAULT_RESRC 50

void 	init_pos(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->h)
	{
	    while (j < map->w)
	    {
	    	if (map->tab[i][j] == '@')
	    	{
	    		map->start.x = i;
	    		map->start.y = j;
	    	}
	    	j++;
	    }
	    i++;
	    j = 0;
	}
}

void 	fill_resrc(t_map *map)
{
	int i;
	int j;
	int k;

	if ((map->resrc.tab = malloc(
                    sizeof(*(map->resrc.tab)) * DEFAULT_RESRC)) == NULL)
		return ;
	for (i = 0, k = 0; i < map->h; i++)
	    for (j = 0; j < map->w; j++)
	    	if (map->tab[i][j] == '+')
	    	{
                if (k > DEFAULT_RESRC)
                    map->resrc.tab = realloc(map->resrc.tab,
                        sizeof(t_vect) * (k + DEFAULT_RESRC));
	    		map->resrc.tab[k].coord = vect(i, j);
	    		map->resrc.tab[k].visited = 0;
	    		k++;
	    	}
	map->resrc.len = k;
}

void 	fin_pos(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->h)
	{
	    while (j < map->w)
	    {
	    	if (map->tab[i][j] == '#')
	    	{
	    		map->finish.x = i;
	    		map->finish.y = j;
	    	}
	    	j++;
	    }
	    i++;
	    j = 0;
	}
}
