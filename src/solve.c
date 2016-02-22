/*
** fjkdh for octocat in /home/amira_s/octo/src
**
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
**
** Started on  Fri Jan  22 16:23:25 2015 AMIRA Syrine
** Last update Fri Jan  22 16:45:07 2015 AMIRA Syrine
*/

#include "my.h"
#include <stdio.h>

void my_memcpy(void *dest, void *src, int size);

int 	game(t_map *map)
{
	t_da	*solutions;
	t_path	path;

	printf("player: (%d, %d) \n", map->start.x, map->start.y);
	printf("finish: (%d,%d) \n" , map->finish.x, map->finish.y);
	printf("(r, pv): (%d, %d)\n", map->init.r, map->init.pv);
	printf("map(w,h): (%d,%d) \n" , map->w, map->h);
	printf("dist = %d\n", dist_exit(map, map->start));
	print_resrc_tab(map);
	solutions = da_new(sizeof(t_path));
	path_new(&path, map);
	get_solutions(map, solutions, &path);
	print_solutions(solutions);
/*	sort_solutions(solutions);
	print_solutions(solutions);*/
	if (solutions->length > 0)
	{
		return (won());
	}
	else
		my_putstr("KO\n");
	return (0);
}

void	*verif(char *argv[])
{
    t_map *map;

    map = malloc(sizeof(t_map));
	if (my_isint(argv[1]) && my_isint(argv[2]))
	{
		map = get_map(argv[3]);
		return (map);
	}
	my_putstr("Arg1 and Arg2 have to be integers\n");
	return (0);
}

int		main(int argc, char *argv[])
{
    t_map *map;

	if (argc == 4)
	{
		map = verif(argv);
		if (map != 0)
		{

			map->init.pv = my_getnbr(argv[1]);
			map->init.r = my_getnbr(argv[2]);
			init_pos(map);
			fin_pos(map);
			fill_resrc(map);

			game(map);
		}
		else
			my_putstr("-> Error invalid arguments/usage\n");
	}
	else
		my_putstr("-> Error number arguments/Usage\n");
	return (0);
}


