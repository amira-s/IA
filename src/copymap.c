#include "my.h"

static char **copy_map_grid(t_map *map)
{
    char **grid;
	int i;
	int j;

	if ((grid = malloc(sizeof(char*) * (map->h))) == NULL)
        return (trace(NULL, "copy_map: malloc failed2\n"));
	for (i = 0; i < map->h; i++)
	{
		if ((grid[i] = malloc((map->w) * sizeof(char))) == NULL)
            return (trace(NULL, "copy_map: malloc failed3\n"));
		for (j = 0; j < map->w; j++)
	 		grid[i][j] = map->tab[i][j];
	}
    return (grid);
}

t_map 		*copy_map(t_map *map)
{
	t_map 	*newmap;
	int i;
	t_vect vect_tmp;

	if ((newmap = malloc(sizeof(*map))) == NULL)
        return (trace(NULL, "copy_map: malloc failed1\n"));
	newmap->init = map->init;
	newmap->start = map->start;
	newmap->finish = map->finish;
	newmap->w = map->w;
	newmap->h = map->h;
    newmap->tab = copy_map_grid(map);
	newmap->resrc = map->resrc;
	if ((newmap->resrc.tab = malloc(sizeof(t_rsrc) * (map->resrc.len))) == NULL)
        return (trace(NULL, "copy_map: malloc failed4\n"));
	for (i = 0; i < map->resrc.len; i++)
    {
        vect_tmp = map->resrc.tab[i].coord;
        newmap->resrc.tab[i].coord = vect_tmp;
        newmap->resrc.tab[i].visited = map->resrc.tab[i].visited;		
    }
	return (newmap);
}
