#include <stdio.h>
#include "error.h"

int main() {
    printf("%s\n", getErrorMessage(MACCES));
    printf("%s\n", getErrorMessage(MNOMEM));
    printf("%s\n", getErrorMessage(MINVAL));
    return 0;
}
