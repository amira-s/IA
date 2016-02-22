#include "my.h"
#include <stdio.h>

#define DEFAULT_RESRC_BUFFER_COUNT 50

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
                    sizeof(t_vect) * DEFAULT_RESRC_BUFFER_COUNT)) == NULL)
		return ;
	for (i = 0, k = 0; i < map->h; i++)
	    for (j = 0; j < map->w; j++)
	    	if (map->tab[i][j] == '+')
	    	{
                if (k > DEFAULT_RESRC_BUFFER_COUNT)
                    map->resrc.tab = realloc(map->resrc.tab,
                        sizeof(t_vect) * (k + DEFAULT_RESRC_BUFFER_COUNT));
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

t_path 		*path_copy(t_path path)
{
	t_path *newpath;
	int i;

	newpath = malloc(sizeof(t_path));
	newpath->dist = path.dist;
	newpath->len = path.len;

	if ((newpath->tab = malloc(path.len * sizeof(t_vect))) == NULL)
        return (trace(NULL, "path_copy: malloc failed"));
	for (i = 0; i <  path.len; i++)
		newpath->tab[i] = path.tab[i];
	return (newpath);
}

t_map 		*copy_map(t_map *map)
{
	t_map 	*newmap;
	int i;
	int j;
	char tmp;
	t_vect vect_tmp;

	if ((newmap = malloc(sizeof(map))) == NULL)
        return (trace(NULL, "copy_map: malloc failed"));

	newmap->init.r = map->init.r;
	newmap->init.pv = map->init.pv;

	newmap->start = map->start;
	newmap->finish = map->finish;

	newmap->resrc = map->resrc;
	if ((newmap->resrc.tab = malloc(sizeof(t_rsrc) * (map->resrc.len))) == NULL)
        return (trace(NULL, "copy_map: malloc failed"));
	for (i = 0; i < map->resrc.len; i++)
		{
			vect_tmp = map->resrc.tab[i].coord;
			newmap->resrc.tab[i].coord = vect_tmp;
			newmap->resrc.tab[i].visited = map->resrc.tab[i].visited;		
		}

	newmap->w = map->w;
	newmap->h = map->h;
	if ((newmap->tab = malloc(sizeof(char*) * (map->h + 1))) == NULL);
        return (trace(NULL, "copy_map: malloc failed"));

	for (i = 0; i < map->h; i++)
	{
		if ((newmap->tab[i] = malloc((map->w + 1) * sizeof(char))) == NULL)
            return (trace(NULL, "copy_map: malloc failed"));
		for (j = 0; j < map->w; j++)
	 	{
	 		tmp = map->tab[i][j];
	 		newmap->tab[i][j] = tmp;
	 		my_putchar(tmp);
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

	for (i = 0; i < solutions->length - 1; i++)
	{
		min = i;
		min_dist = ((t_path*)da_at(solutions, min))->dist;
		for (k = i + 1; k <  solutions->length; k++)
		{
			if (((t_path*)da_at(solutions, k))->dist  < min_dist)
				min = k;
		}
		if (min != i)
			da_swap(solutions, i, min);
	}

}

void	print_resrc(t_map *map, int i)
{
	my_putstr("resrc ");
	my_put_nbr(i);
	my_putstr(": (");
	my_put_nbr(map->resrc.tab[i].coord.x);
	my_putstr(", ");
	my_put_nbr(map->resrc.tab[i].coord.y);
	my_putstr("), visited = ");
	my_put_nbr(map->resrc.tab[i].visited);
	my_putstr(" \n");
}

void		get_solutions(t_map *map, t_da *solutions, t_path *path)
{
	int 	i;
	int 	newpv;
	t_vect 	pos;
	t_map 	*map_tmp;
	t_path  *path_tmp;

	print_path(path);
	if (map->init.pv >= dist_exit(map, map->start))
	{
		my_putstr("case 1\n");
        path_push(path, map->finish);
		da_push(solutions, path_copy(*path));
		my_putstr("solutions atm --------- \n");
		print_solutions(solutions);
		my_putstr("------------\n");
	}
	else
	{
		my_putstr("case 2\n");
		for (i = 0; i < map->resrc.len; i++)
		{
			print_resrc(map, i);
			if (map->resrc.tab[i].visited == 0)
			{
				newpv = reachable(map, map->resrc.tab[i].coord.x, map->resrc.tab[i].coord.y);
				my_putstr("newpv = ");
				my_put_nbr(newpv);
				my_putstr("\n");
				if (newpv != 0)
				{
					map_tmp = copy_map(map);
					path_tmp = path_copy(*path);

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
	my_putstr("before pop:"); print_path(path); /* DEBUG */
	path_pop(path);
	my_putstr("after pop:"); print_path(path); /* DEBUG */
}

void print_resrc_tab(t_map *map)
{
	int i;

	for (i = 0; i < map->resrc.len; i++)
	{
		printf("resrc %d: (%d, %d), visited = %d\n", i, map->resrc.tab[i].coord.x, map->resrc.tab[i].coord.y, map->resrc.tab[i].visited);
	}
}

void	path_new(t_path *path, t_map *map)
{
	path->tab = malloc(100 * sizeof(t_vect));
	path->tab[0].x = map->start.x;
	path->tab[0].y = map->start.y;
	path->dist = 0;
	path->len = 1;
}


