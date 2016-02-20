/*
** asciifun.c for octocat in /home/amira_s/octo/src
**
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
**
** Started on  Fri Jan  22 16:23:25 2015 AMIRA Syrine
** Last update Fri Jan  22 16:45:07 2015 AMIRA Syrine
*/

#ifndef __MY_STRUCT__
# define __MY_STRUCT__

#include "../lib/vect.h"

typedef struct s_init
{
	int r;
	int pv;
} t_init;

typedef struct s_rsrc
{
	t_vect coord;
	int visited;
} t_rsrc;

typedef struct s_vect_arr
{
	t_rsrc *tab;
	int len;
} t_vect_arr;

typedef struct s_path
{
	t_vect *tab;
	int len;
	int dist;
} t_path;

typedef struct s_map
{
	t_init 	init;
	t_vect 	start;
	t_vect 	finish;
	t_vect_arr resrc;
	int w;
	int h;
	char **tab;
} 	t_map;


#endif
