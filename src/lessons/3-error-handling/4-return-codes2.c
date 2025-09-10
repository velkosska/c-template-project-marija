#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // rename(): 0 on success, nonzero on error
    if (rename("missing.txt", "renamed.txt") != 0) {
        puts("rename() -> error (nonzero return)");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

