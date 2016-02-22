void my_putstr(char *str);

void *trace(void *ptr, char *msg)
{
    my_putstr(msg);
    return (ptr);
}
