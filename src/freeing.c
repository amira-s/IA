/*
** freeing.c for AI in /home/amira_s/src/AI
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Feb 22 09:15:10 2016 AMIRA Syrine
** Last update Fri Mar 04 16:52:33 2016 AMIRA Syrine
*/

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
