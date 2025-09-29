#include "library.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    IVec v = {0};
    if (!iv_read(&v)) { fprintf(stderr,"alloc/input error\n"); free(v.data); return 1; }
    iv_print(&v);
    printf("sum=%lld avg=%g\n", iv_sum(&v), iv_avg(&v));
    free(v.data);
}
