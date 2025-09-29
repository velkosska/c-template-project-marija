#include <stdio.h>
#include <stdint.h>

int main(void){
    int x = 7;
    float f1 = (float)x;                

    float f2 = *(float*)&x;

    uint32_t bits = 0x40000000u;
    float two = *(float*)&bits;

    printf("f1 (cast) = %g\n", f1);
    printf("f2 (reinterpret) = %g  (undefined behavior!)\n", f2);
    printf("two (reinterpret 0x40000000) = %g\n", two);
}
