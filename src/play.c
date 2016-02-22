#include "my.h"
#include <stdio.h>

int 	dist_exit(t_map *map, t_vect v)
{
	return (vect_dist(v, map->finish));
}

int 	reachable(t_map *map, int x, int y)
{
	int dist;
	int newpv;

	dist = abs(x - map->start.x) + abs(y - map->start.y);
	newpv = map->init.pv - dist + map->init.r;
	if (map->init.pv > dist)
		return (newpv);
	else
		return (0);
}

t_map 		*copy_map(t_map *map)
{
	t_map 	*newmap;
	int i;
	int j;
	char tmp;
	t_vect vect_tmp;

	if ((newmap = malloc(sizeof(*map))) == NULL)
        return (trace(NULL, "copy_map: malloc failed1"));

	newmap->init = map->init;
	newmap->start = map->start;
	newmap->finish = map->finish;

	newmap->w = map->w;
	newmap->h = map->h;

	if ((newmap->tab = malloc(sizeof(char*) * (map->h))) == NULL)
        return (trace(NULL, "copy_map: malloc failed2"));
	for (i = 0; i < map->h; i++)
	{
		if ((newmap->tab[i] = malloc((map->w) * sizeof(char))) == NULL)
            return (trace(NULL, "copy_map: malloc failed3"));
		for (j = 0; j < map->w; j++)
	 	{
	 		tmp = map->tab[i][j];
	 		newmap->tab[i][j] = tmp;
	 	}

		newmap->resrc = map->resrc;
	if ((newmap->resrc.tab = malloc(sizeof(t_rsrc) * (map->resrc.len))) == NULL)
        return (trace(NULL, "copy_map: malloc failed4"));
	for (i = 0; i < map->resrc.len; i++)
		{
			vect_tmp = map->resrc.tab[i].coord;
			newmap->resrc.tab[i].coord = vect_tmp;
			newmap->resrc.tab[i].visited = map->resrc.tab[i].visited;		
		}

	}
	return (newmap);
}

void		sort_solutions(t_da *solutions)
{
	int 	i;
	int 	k;
	int  	min;
	int     min_dist;

	for (i = 0; i < solutions->length - 2; i++)
	{
		min = i;
		min_dist = ((t_path*)da_at(solutions, min))->dist;
		for (k = i + 1; k <  solutions->length - 1 ; k++)
		{
			if (((t_path*)da_at(solutions, k))->dist  < min_dist)
				min = k;
		}
		if (min != i)
			da_swap(solutions, i, min);
	}
	print_solutions(solutions);

}

void		get_solutions(t_map *map, t_da *solutions, t_path *path)
{
	int 	i;
	int 	newpv;
	t_vect 	pos;
	t_map 	*map_tmp;
	t_path  *path_tmp;

	if (map->init.pv >= dist_exit(map, map->start))
	{
        path_push(path, map->finish);
		da_push(solutions, path_copy(path));
	}
	else
	{
		for (i = 0; i < map->resrc.len; i++)
		{
			if (map->resrc.tab[i].visited == 0)
			{
				newpv = reachable(map, map->resrc.tab[i].coord.x, map->resrc.tab[i].coord.y);
				if (newpv != 0)
				{
					map_tmp = copy_map(map);
					path_tmp = path_copy(path);
					pos = map_tmp->start = map->resrc.tab[i].coord;
					map_tmp->init.pv = newpv;
					map_tmp->resrc.tab[i].visited = 1;
					path_tmp->dist += vect_dist(map->resrc.tab[i].coord, map->start);
					path_push(path_tmp, pos);
					get_solutions(map_tmp, solutions, path_tmp);
				}
			}
		}
	}
	path_pop(path);
}






