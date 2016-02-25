#include "dynamic_array.c"

int main() {
    int result = 0;

    result += !test_my_memcpy();
    result += !test_da_swap();
    return !(result != 0);
}
