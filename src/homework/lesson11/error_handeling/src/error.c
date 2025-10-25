#include "error.h"

const char *getErrorMessage(ErrorCode code) {
    switch (code) {
        case MACCES: return "Permission denied";
        case MNOMEM: return "Out of memory";
        case MINVAL: return "Invalid argument";
        default: return "Unknown error";
    }
}
