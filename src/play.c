/*
** play.c for AI in /home/amira_s/src/AI
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Feb 22 09:15:10 2016 AMIRA Syrine
** Last update Fri Mar 04 16:52:33 2016 AMIRA Syrine
*/

#include "my.h"

#define DIST_EXIT(map, v) (vect_dist((v), (map)->finish))

int reachable(t_map *map, int x, int y)
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

void sort_solutions(t_da *solutions)
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

#define MAKES_MAP_PATH_COPIES(map, path, map_tmp, path_tmp) do { \
} while (0);

#define FREE_MAP_PATH(map, path) do {\
    free_map(map_tmp); \
    free_path(path_tmp); \
} while (0);

static void step_map(t_da *solutions, t_map *map, t_path *path,
                     int newpv, int i)
{
	t_vect 	pos;
	t_map 	*map_tmp;
	t_path  *path_tmp;

    map_tmp = copy_map(map);
    map_tmp->init.pv = newpv;
    map_tmp->resrc.tab[i].visited = 1;

    path_tmp = path_copy(path);

    pos = map_tmp->start = map->resrc.tab[i].coord;
    path_push(path_tmp, pos);
    get_solutions(map_tmp, solutions, path_tmp);

    free_map(map_tmp);
}

static void scan_resources(t_map *map, t_da *solutions, t_path *path)
{
	int 	i;
	int 	newpv;

    for (i = 0; i < map->resrc.len; i++)
        if (map->resrc.tab[i].visited == 0)
        {
            newpv = reachable(map, map->resrc.tab[i].coord.x,
                              map->resrc.tab[i].coord.y);
            if (newpv != 0)
            {
                step_map(solutions, map, path, newpv, i);
            }
        }
}

void get_solutions(t_map *map, t_da *solutions, t_path *path)
{
	if (map->init.pv >= DIST_EXIT(map, map->start))
	{
        path_push(path, map->finish);
		da_push(solutions, path);
	}
	else
        scan_resources(map, solutions, path);
	path_pop(path);
}
