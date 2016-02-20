#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct s_da {
    int size;
    void* data;
    int max;
    int length;
    int index;
} t_da;
t_da *da_new(int el_size);
t_da *da_from(int el_size, void* arr, int el_count, int max_el_count);
void da_push(t_da *da, void *data);
void *da_pop(t_da *da);
void *da_at(t_da *da, int i);
void *da_next(t_da *da);
void da_reset(t_da *da);
void da_foreach(t_da *da, void(*f)(void*, int, void*));
int da_swap(t_da *da, int i, int j);

#endif /* DYNAMIC_ARRAY_H */
