#include <stdio.h>
#include "bits.h"

static void print_byte(unsigned char byte) {
    for (int i = 7; i >= 0; i--) printf("%d", (byte >> i) & 1);
}

void print_bits(const void *ptr, size_t size) {
    const unsigned char *bytes = (const unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        print_byte(bytes[i]);
        printf(" ");
    }
    printf("\n");
}
