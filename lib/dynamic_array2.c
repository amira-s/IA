#include <stdlib.h>
#include "dynamic_array.h"
#include <string.h>

void my_swap(void* a, void* b, int size);

void *da_next(t_da *da)
{
    if (da->index < da->length)
        return (da_at(da, da->index));
    return (NULL);
}

void da_reset(t_da *da)
{
    da->index = 0;
}

void da_foreach(t_da *da, void(*fn)(void*, int, void*))
{
    int i;

    for (i = 0; i < da->length; i++)
        fn(da_at(da, i), i, da->data);
}

int da_swap(t_da *da, int i, int j)
{
    if (i < 0 || i > da->length || j < 0 || j > da->length)
        return (1);
    if (i != j)
        my_swap((char*)da->data + i, (char*)da->data + j, da->size);
    return (0);
}
