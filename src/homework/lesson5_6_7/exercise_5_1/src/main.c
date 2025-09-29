#include <stdio.h>
#include "rectangle.h"

int main(void) {
    Rectangle r = { .width = 10, .height = 5 };
    printf("Initial: width=%d height=%d\n", r.width, r.height);
    printf("Area = %d\n", area(r));

    grow(&r, 3, -2);
    printf("After grow(+3, -2): width=%d height=%d\n", r.width, r.height);
    printf("Area = %d\n", area(r));

    grow(&r, -100, 0);
    printf("After grow(-100, 0): width=%d height=%d\n", r.width, r.height);
    printf("Area = %d (expected 0)\n", area(r));
    return 0;
}
