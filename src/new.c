#include <stdio.h>

typedef union {
    int i;
    float f;
} U;

int main() {
    U u;
    u.i = 1065353216;  // bit pattern for 1.0f
    printf("%f\n", u.f);
    return 0;
}