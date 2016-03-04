#ifndef __MY__
# define __MY__

#include <stdlib.h>
#include <unistd.h>
#include "my_struct.h"
#include "../lib/dynamic_array.h"
#include "../lib/vect.h"
#include "../lib/colors.h"
#include "config.h"

#include <stdio.h> /* DEBUG */

/*/lib*/
void		my_putchar(char c);
int			my_getnbr();
void		my_put_nbr();
void		my_putstr(char *);
int			my_strlen(char *);
int			my_strcmp(char *, char *);
char		*my_strcat(char *, char *);
char		*my_strdup(char *);
void        my_swap(void* a, void* b, int size);
void        *noop(void*);
void        *trace(void*, char* msg);
void 		my_memcpy(void *dest, void *src, int size);
int 		my_isint(char *str);

/*path.c*/
t_vect      path_pop(t_path *p);
void        path_push(t_path *p, t_vect v);
void		path_new(t_path *path, t_map *map);
t_path 		*path_copy(t_path *path);

/*init.c*/
void 		init_pos(t_map *);
void 		fin_pos(t_map *);
void 		fill_resrc(t_map *);

/*play.c*/
int      	dist_exit(t_map *map, t_vect v);
int 		reachable(t_map *map, int x, int y);
void		sort_solutions(t_da *solutions);
void		get_solutions(t_map *map, t_da *solutions, t_path *path);

/*copymap.c*/
t_map 		*copy_map(t_map *map);

/*print.c*/
void        print_path(t_path *path);
void        print_solutions(t_da *solutions);
void 		print_resrc_tab(t_map *map);
void 		print_resrc(t_map *map, int i);

/*getmap.c*/
void    	freetab(t_map *);
int    		check_map(t_map *);
void    	*get_map(char *input);
char 		*getfilename();
void    	print_t(t_map *map);

/*outcome.c*/
int         won();
void        print_map(t_map *map);
void        move(t_map *map, t_path *path);

/*freeing*/
void        free_map(t_map *map);
void        free_path(t_path *path);

#endif /* __MY__ */
