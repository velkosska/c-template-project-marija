#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

void readBook(const char* fileName, char** contents) {
    FILE* f = fopen(fileName, "r");
    if(!f){
        fprintf(stderr, "Error opening '%s': %s\n", fileName, strerror(errno));
        exit(EXIT_FAILURE);
    }
    size_t cap = 8192, len = 0;
    char* buf = malloc(cap);
    if(!buf){
        fprintf(stderr, "Allocation failure: %s\n", strerror(errno));
        fclose(f);
        exit(EXIT_FAILURE);
    }

    int c;
    while((c = fgetc(f)) != EOF){
        if(len + 1 >= cap){
            cap *= 2;
            char* tmp = realloc(buf, cap);
            if(!tmp){
                fprintf(stderr, "Reallocation failure: %s\n", strerror(errno));
                free(buf);
                fclose(f);
                exit(EXIT_FAILURE);
            }
            buf = tmp;
        }
        buf[len++] = isalpha((unsigned char)c) ? (char)tolower(c) : ' ';
    }
    buf[len] = '\0';
    fclose(f);
    *contents = buf;
}
