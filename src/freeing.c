#include "my.h"

void free_char_grid(char **grid, int height)
{
    int y;

    for (y = 0; y < height; y++)
        free(grid[y]);
    free(grid);
}

void free_map(t_map *map)
{
    free_char_grid(map->tab, map->h);
    free(map);
}

void free_path(t_path *path)
{
    free(path->tab);
    free(path);
}
