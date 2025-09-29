#include "library.h"
#include <stdio.h>
#include <stdlib.h>

static int iv_grow(IVec *v){
    size_t ncap = v->cap ? v->cap*2 : 8;
    int *p = (int*)realloc(v->data, ncap * sizeof *p);
    if(!p) return 0;
    v->data = p; v->cap = ncap; return 1;
}
int iv_push(IVec *v, int x){ if(v->len==v->cap && !iv_grow(v)) return 0; v->data[v->len++]=x; return 1; }
int iv_read(IVec *v){
    int x;
    while (printf("number (neg to stop): "), fflush(stdout), scanf("%d",&x)==1){
        if (x < 0) break;
        if (!iv_push(v,x)) return 0;
    }
    return 1;
}
long long iv_sum(const IVec *v){ long long s=0; for(size_t i=0;i<v->len;i++) s+=v->data[i]; return s; }
double iv_avg(const IVec *v){ return v->len? (double)iv_sum(v)/v->len : 0.0; }
void iv_print(const IVec *v){ for(size_t i=0;i<v->len;i++) printf("%d%c", v->data[i], i+1==v->len?'\n':' '); }
