#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char *a, const char *b){
    if (!a || !b) return NULL;
    size_t la = strlen(a), lb = strlen(b);
    char *out = (char*)malloc(la + lb + 1);
    if (!out) return NULL;
    memcpy(out, a, la);
    memcpy(out + la, b, lb);
    out[la + lb] = '\0';
    return out;               
}

int main(void){
    char *c = concat("hello", " world");
    if (c){ puts(c); free(c); }
    return 0;
