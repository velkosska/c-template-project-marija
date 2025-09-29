#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *heap_arr = (int*)malloc(1000 * sizeof *heap_arr);
    printf("sizeof(heap_arr) = %zu (pointer size)\n", sizeof heap_arr);

    int stack_arr[1000];
    printf("sizeof(stack_arr) = %zu (1000 * sizeof(int))\n", sizeof stack_arr);

    free(heap_arr);
}

/*sizeof(heap_arr) is the size of a pointer (e.g., 8 on x86-64).
sizeof(stack_arr) is the entire array (1000 * sizeof(int)), because the array hasn’t decayed to a pointer in the sizeof operator.*/