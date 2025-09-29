#pragma once
#include <stddef.h>

typedef struct { int *data; size_t len, cap; } IVec;
int  iv_push(IVec *v, int x);
int  iv_read(IVec *v);        // reads until negative
long long iv_sum(const IVec *v);
double iv_avg(const IVec *v);
void iv_print(const IVec *v);
