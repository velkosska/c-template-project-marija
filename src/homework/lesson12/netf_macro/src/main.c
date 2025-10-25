#include <stdio.h>

typedef struct {
    int a;
    double b;
    char c;
} repro_t;

typedef struct {
    char *name;
    int offset;
} netField_t;

#define NETF(x) #x, (int)&(((repro_t*)0)->x)

netField_t reproFields[] = {
    { NETF(a) },
    { NETF(b) },
    { NETF(c) }
};

int main() {
    for (int i = 0; i < 3; i++) {
        printf("Field: %s, Offset: %d\n", reproFields[i].name, reproFields[i].offset);
    }
    return 0;
}
