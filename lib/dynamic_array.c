#include <string.h>
#include <stdlib.h>
#include "dynamic_array.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define DEFAULT_BUFFER_EL_COUNT 50
#define REALLOC_BUFFER_STEPS 1

t_da *da_new(int el_size)
{
    t_da *da;
    if ((da = malloc(sizeof(t_da))) == NULL)
        return (NULL);
    if ((da->data = malloc(el_size * DEFAULT_BUFFER_EL_COUNT)) == NULL)
        return (NULL);
    da->index = 0;
    da->size = el_size;
    da->max = 0;
    da->length = 0;
    return (da);
}

t_da *da_from(int el_size, void* arr, int el_count, int max_el_count)
{
    t_da *da;
    void* buffer;

    da = da_new(el_size);
    da->length = el_count;
    if ((buffer = malloc(el_size * max_el_count)) == NULL)
        return (NULL);
    da->data = buffer;
    memcpy(buffer, arr, el_count * el_size);
    return (da);
}

void da_push(t_da *da, void *data)
{
    void* dest;
    int buffer_size;

    if (da->length <= da->max)
    {
        buffer_size = da->size * MAX(da->max, DEFAULT_BUFFER_EL_COUNT);
        da->data =
            realloc(da->data, buffer_size * (1 + REALLOC_BUFFER_STEPS));
        da->max *= 1 + REALLOC_BUFFER_STEPS;
    }
    dest = (char*)da->data + (da->length * da->size);
    memcpy(dest, data, da->size);
    da->length += 1;
}

void *da_pop(t_da *da)
{
    void *data;

    data = da_at(da, da->length - 1);
    da->length -= 1;
    return (data);
}

void *da_at(t_da *da, int i)
{
    if (da->length <= i)
        return (NULL);
    return ((char*)da->data + (i * da->size));
}
