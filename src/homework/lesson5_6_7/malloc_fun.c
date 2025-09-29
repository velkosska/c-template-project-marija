#include <stdio.h>
#include <stdlib.h>

typedef struct { int *data; size_t len, cap; } IVec;

int grow(IVec *v){
    size_t ncap = v->cap ? v->cap*2 : 8;
    int *p = (int*)realloc(v->data, ncap * sizeof *p);
    if(!p) return 0;
    v->data = p; v->cap = ncap;
    return 1;
}

int push(IVec *v, int x){
    if (v->len == v->cap && !grow(v)) return 0;
    v->data[v->len++] = x;
    return 1;
}

int read_numbers(IVec *v){
    int x;
    while (printf("number (neg to stop): "), fflush(stdout), scanf("%d",&x)==1){
        if (x < 0) break;
        if (!push(v, x)) return 0;
    }
    return 1;
}

void stats(const IVec *v){
    long long sum = 0;
    for(size_t i=0;i<v->len;i++) sum += v->data[i];
    double avg = v->len ? (double)sum / v->len : 0.0;
    printf("count=%zu sum=%lld avg=%.6f\n", v->len, sum, avg);
    for(size_t i=0;i<v->len;i++) printf("%d%c", v->data[i], i+1==v->len?'\n':' ');
}

int main(void){
    IVec v = {0};
    if (!read_numbers(&v)) { fprintf(stderr,"alloc/input error\n"); free(v.data); return 1; }
    stats(&v);
    free(v.data);
}
