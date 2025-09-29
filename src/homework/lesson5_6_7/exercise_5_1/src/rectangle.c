#include "rectangle.h"
#include <limits.h>


int area(Rectangle r) {
    if (r.width < 0 || r.height < 0) return -1;
    long long w = r.width;
    long long h = r.height;
    long long a = w * h;
    if (a > (long long)INT_MAX) return -1; 
    return (int)a;
}

void grow(Rectangle *r, int dw, int dh) {
    if (!r) return;
    long new_w = (long)r->width + (long)dw;
    long new_h = (long)r->height + (long)dh;
    if (new_w < 0) new_w = 0;
    if (new_h < 0) new_h = 0;
    r->width = (int)new_w;
    r->height = (int)new_h;
}
