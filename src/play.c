#include "my.h"

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

void		sort_solutions(t_da *solutions)
{
	int 	i;
	int 	k;
	int  	min;

	for (i = 0; i < solutions->length - 1; i++)
	{
		min = i;
		for (k = i + 1; k < solutions->length ; k++)
		{
			if (((t_path*)da_at(solutions, k))->dist <
                    ((t_path*)da_at(solutions, min))->dist)
				min = k;
		}
		if (min != i)
			da_swap(solutions, i, min);
	}
}


static void scan_resources(t_map *map, t_da *solutions, t_path *path)
{
	int 	i;
	int 	newpv;
	t_vect 	pos;
	t_map 	*map_tmp;
	t_path  *path_tmp;

    for (i = 0; i < map->resrc.len; i++)
        if (map->resrc.tab[i].visited == 0)
        {
            newpv = reachable(map, map->resrc.tab[i].coord.x,
                              map->resrc.tab[i].coord.y);
            if (newpv != 0)
            {
                map_tmp = copy_map(map);
                path_tmp = path_copy(path);
                pos = map_tmp->start = map->resrc.tab[i].coord;
                map_tmp->init.pv = newpv;
                map_tmp->resrc.tab[i].visited = 1;
                path_push(path_tmp, pos);
                get_solutions(map_tmp, solutions, path_tmp);
                free_map(map_tmp);
                free_path(path_tmp);
            }
        }
}

void get_solutions(t_map *map, t_da *solutions, t_path *path)
{
	if (map->init.pv >= dist_exit(map, map->start))
	{
        path_push(path, map->finish);
		da_push(solutions, path_copy(path));
	}
	else
        scan_resources(map, solutions, path);
	path_pop(path);
}
