#include <stdio.h>
#include "super_assert.h"

int main(void) {
    int x = 5;
    super_assert(x == 5, "x should be 5");
    super_assert(x != 5, "x should not be 5");
    puts("after assertions");
    return 0;
}
