#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zipf.h"

static char **W = NULL;
static int  *F = NULL;

static int cmp_desc_freq_then_alpha(const void *a, const void *b){
    size_t ia = *(const size_t*)a;
    size_t ib = *(const size_t*)b;
    if(F[ia] != F[ib]) return (F[ib] - F[ia]);       
    return strcmp(W[ia], W[ib]);
}

int main(int argc, char** argv){
    if(argc < 3){
        fprintf(stderr, "Usage: %s input.txt output.dat\n", argv[0]);
        return 1;
    }

    char* book = NULL;
    char** words = NULL;
    int* freqs = NULL;
    int n = 0;

    readBook(argv[1], &book);
    countWords(book, &words, &freqs, &n);
    free(book);

    size_t *idx = malloc((size_t)n * sizeof(size_t));
    if(!idx){ perror("malloc"); return 1; }
    for(int i = 0; i < n; i++) idx[i] = (size_t)i;
    W = words; F = freqs;
    qsort(idx, (size_t)n, sizeof(size_t), cmp_desc_freq_then_alpha);

    FILE* out = fopen(argv[2], "w");
    if(!out){ perror("fopen"); free(idx); return 1; }

    for(int r = 0; r < n; r++){
        size_t w = idx[r];
        fprintf(out, "%d %d %s\n", r + 1, freqs[w], words[w]);
    }
    fclose(out);

    free(idx);
    for(int i = 0; i < n; i++) free(words[i]);
    free(words);
    free(freqs);
    return 0;
}
