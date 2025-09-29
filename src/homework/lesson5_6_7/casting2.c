#include <stdio.h>

int main(void){
    int x = 0;
    double *d_ptr = (double*)&x;   // reads 8 bytes from a 4-byte object
    printf("x as double: %g\n", *d_ptr);

    float *f_ptr = (float*)&x;    
    printf("x as float: %g\n", *f_ptr);
}



/*With double*, you read 8 bytes starting at &x, overrunning the 4-byte int , undefined behavior and seemingly random values across runs.
With float*, the size matches; the bytes of x are all zero, so many platforms print 0. It’s still UB due to strict aliasing; the “works” outcome is incidental.*/