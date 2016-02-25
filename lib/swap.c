#include <stdlib.h>

void my_memcpy(void *dest, void *src, int size);

void my_swap(void* a, void* b, int size)
{
    void* tmp;

    if ((tmp = malloc(size)) == NULL)
        return ;
    my_memcpy(tmp, a, size);
    my_memcpy(a, b, size);
    my_memcpy(b, tmp, size);
    free(tmp);
}
