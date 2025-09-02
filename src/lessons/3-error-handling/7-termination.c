#include <stdlib.h>
#include <stdio.h>

void foo(){
    printf("Inside foo()\n");
    exit(EXIT_FAILURE);
    //quick_exit(EXIT_FAILURE);
    //abort();
}

int main(void) {
    foo();
    printf("This will never be printed\n");
}