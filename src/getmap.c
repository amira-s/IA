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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void    freetab(t_map *map)
{
    int i;

    for (i = 0; i < map->h; i++)
        free(map->tab[i]);
    free(map->tab);
    free(map); 
}

void    filltab(int fd, t_map *map)
{
    int k;
    int j;
    int c;
    char tmp;

    j = 0;
    k = 0;
    map->tab = malloc(100 * sizeof(char));
    c = read(fd, &tmp, 1);
    while (c)
    {
        map->tab[k] = malloc(100 * sizeof(char));
        while (tmp != '\n' && c)
        {
            map->tab[k][j++] = tmp;
            c = read(fd, &tmp, 1);
            map->w = j;
        } 
        k++;
        j = 0;
        c = read(fd, &tmp, 1);
    }
    map->h = k;
}

int    check_map(t_map *map)
{
    int i;
    int j;
    int t;
    int s;
    int e;

    t = s = e = 0;
    for (i = 0; i < map->h; i++)
    {
        for (j = 0; j < map->w; j++)
        {
            if (map->tab[i][j] == '#')
                e++;
            else if (map->tab[i][j] == '@')
                s++;
            else if (map->tab[i][j] == ' ' || map->tab[i][j] == '+')
                t++;
            else
                return (0);
        }
    }
    if (s == 1 && e == 1)
        return (1);
    else
        return (0);
}

void    print_t(t_map *map)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < map->h; i++)
    {
        for (j = 0; j < map->w; j++)
        {
            my_putchar(map->tab[i][j]);
        }
            my_putchar('\n');
    }
            my_putstr("~~~~~~~ \n");
}

#define ERR_CORRUPTED_MAP "\033[91m-> La map que vous essayez de charger\
 est corrompue.\033[0m\n"

#define ERR_LOADING "\033[91m-> Erreur lors du chargement du \
fichier.\033[0m\n"

void    *get_map(char *input)
{
    int   fd;
    t_map *map;

    map = malloc(sizeof(t_map));
    fd = open(input, O_RDWR);
    if (fd == -1)
    {
        my_putstr(ERR_LOADING);
        return (0);
    }
    else
        filltab(fd, map);
    print_t(map);
    if (check_map(map) == 0)
    {
        my_putstr(ERR_CORRUPTED_MAP);
        return (0);
    }
    else
        return (map);
    return (map);
}
