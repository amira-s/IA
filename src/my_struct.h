/*
** my_struct.h for AI in /home/amira_s/src/AI
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Feb 22 09:15:10 2016 AMIRA Syrine
** Last update Fri Mar 04 16:52:33 2016 AMIRA Syrine
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
