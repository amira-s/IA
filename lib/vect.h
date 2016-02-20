#ifndef VECT_H
#define VECT_H

typedef struct s_vect
{
	int x;
	int y;
} t_vect;

t_vect vect(int x, int y);
t_vect vect_add(t_vect v1, t_vect v2);
t_vect vect_sub(t_vect v1, t_vect v2);
t_vect vect_mult(t_vect v1, t_vect v2);
t_vect vect_div(t_vect v1, t_vect v2);
t_vect vect_abs(t_vect v);
int vect_length(t_vect v);
int vect_dist(t_vect v1, t_vect v2);

#endif /* VECT_H */
