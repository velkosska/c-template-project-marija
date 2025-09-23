#include "name_length.h"
#include <ctype.h>

int name_length(const char *name) {
    if (!name) return 0;
    int count = 0;
    for (const char *p = (const char  *)name; *p; ++p) {
        if (!isspace(*p)) ++count;
    }
    return count;
}
