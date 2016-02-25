#include <stdio.h>
#include <string.h>

#include "../lib/dynamic_array.h"
void my_memcpy(void *dest, void *src, int size);


int test_my_memcpy() {
    char str1[6] = "yoman";
    char str2[6] = "higuy";
    printf("before memcpy: %s <=> %s\n", str1, str2);
    my_memcpy(str1, str2, sizeof(str1));
    printf("after memcpy:  %s <=> %s\n", str1, str2);
    return !strcmp(str1, str2);
}

int test_da_swap() {
    t_da *myda1;
    
    char mystr1[10] = "123>567.90";
    char reference[10] = "123>567.90";

    myda1 = da_from(sizeof(char) * 2, mystr1, 5, 20);
    printf("->size:{%d}\n", myda1->size);
    printf("before swap: \"%s\"\n", myda1->data);
    da_swap(myda1, 1, 3);
    printf("after swap:  \"%s\"\n", myda1->data);
    printf("%c", ((char*)myda1->data)[1*2]);
    printf("%c", reference[3*2]);
    
    return (((char*)myda1->data)[1*2] == reference[3*2] &&
            ((char*)myda1->data)[3*2] == reference[1*2]);
}

int main() {
    int result = 0;

    result += !test_my_memcpy();
    result += !test_da_swap();
    return !(result != 0);
}
