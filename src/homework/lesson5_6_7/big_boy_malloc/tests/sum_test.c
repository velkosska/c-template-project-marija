#include <assert.h>
#include <stdlib.h>
#include "library.h"   

int main(void) {
    IVec v = {0};

    if (!iv_push(&v, 1)) return 2;
    if (!iv_push(&v, 2)) { free(v.data); return 2; }
    if (!iv_push(&v, 3)) { free(v.data); return 2; }

    long long s = iv_sum(&v);
    double a = iv_avg(&v);

    assert(s == 6);
    assert(a == 2.0);

    free(v.data);
    return 0;
}
