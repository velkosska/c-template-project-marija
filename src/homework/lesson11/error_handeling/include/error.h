#ifndef ERROR_H
#define ERROR_H

typedef enum {
    MACCES,
    MNOMEM,
    MINVAL
} ErrorCode;

const char *getErrorMessage(ErrorCode code);

#endif
