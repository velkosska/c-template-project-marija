#include <stdio.h>
#include <string.h>

#define ROOT_MAGIC 0x00baba55L
#define USER_MARK  0xdeadbeefL

void root_privileged_print(const char* message, long user) {
    if (user == ROOT_MAGIC) {
        printf("Root says: %s\n", message);
    }
    if (user == USER_MARK) {
        printf("Users do not have access to this function\n");
    }
}

void injection(void) {
    volatile long marker = USER_MARK;  
    long *sp = (long *)&marker;
    int seen = 0;

    for (long *p = sp; p < sp + 4096; ++p) {
        if (*p == USER_MARK) {
            if (seen++) { *p = ROOT_MAGIC; return; }
        }
    }
    for (long *p = sp; p > sp - 4096; --p) {
        if (*p == USER_MARK) {
            if (seen++) { *p = ROOT_MAGIC; return; }
        }
    }
}

int main(void) {
    volatile long user = USER_MARK; 
    injection();
    root_privileged_print("ALL YOUR BASE ARE BELONG TO US", user);
    return 0;
}

/*Used the following line to compile
cc -O0 -fno-stack-protector injection.c -o injection */