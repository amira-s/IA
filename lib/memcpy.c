void my_memcpy(void *dest, void *src, int size)
{
    int i;

    for (i = 0; i < size; i++)
        *(char*)dest = *(char*)src;
}
