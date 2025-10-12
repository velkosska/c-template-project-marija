#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "zipf.h"

static int cmp_strptr(const void* a, const void* b){
    return strcmp(*(const char**)a, *(const char**)b);
}

void countWords(const char* book, char*** words, int** freqs, int* nWords){
    char* work = strdup(book);
    if(!work){
        fprintf(stderr, "Allocation failure: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    size_t cap = 1024, n = 0;
    char** list = malloc(cap * sizeof(char*));
    if(!list){
        fprintf(stderr, "Allocation failure: %s\n", strerror(errno));
        free(work);
        exit(EXIT_FAILURE);
    }

    char* saveptr;
    for(char* tok = strtok_r(work, " \t\r\n", &saveptr);
        tok;
        tok = strtok_r(NULL, " \t\r\n", &saveptr)) {

        if(*tok == '\0') continue;
        if(n == cap){
            cap *= 2;
            char** tmp = realloc(list, cap * sizeof(char*));
            if(!tmp){
                fprintf(stderr, "Reallocation failure: %s\n", strerror(errno));
                for(size_t i = 0; i < n; i++) free(list[i]);
                free(list);
                free(work);
                exit(EXIT_FAILURE);
            }
            list = tmp;
        }
        list[n] = strdup(tok);
        if(!list[n]){
            fprintf(stderr, "Allocation failure: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        n++;
    }
    free(work);
    if(n == 0){ *words = NULL; *freqs = NULL; *nWords = 0; return; }

    qsort(list, n, sizeof(char*), cmp_strptr);

    char** uniq = malloc(n * sizeof(char*));
    int* freq = malloc(n * sizeof(int));
    if(!uniq || !freq){
        fprintf(stderr, "Allocation failure: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    size_t m = 0;
    for(size_t i = 0; i < n;){
        size_t j = i + 1;
        while(j < n && strcmp(list[i], list[j]) == 0) j++;
        uniq[m] = list[i];
        freq[m] = (int)(j - i);
        for(size_t k = i + 1; k < j; k++) free(list[k]);
        m++;
        i = j;
    }
    free(list);

    *words = uniq;
    *freqs = freq;
    *nWords = (int)m;
}
