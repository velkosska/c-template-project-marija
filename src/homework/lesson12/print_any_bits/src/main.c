#include "bits.h"

int main(void) {
    int x = 0xDEADBEEF;
    double y = 3.14;
    char c = 'A';
    print_bits(&x, sizeof(x));
    print_bits(&y, sizeof(y));
    print_bits(&c, sizeof(c));
    return 0;
}
