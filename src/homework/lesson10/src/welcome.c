#include <stdio.h>
#include <stdlib.h>
#include "welcome.h"


#ifndef LANGUAGE
  #define LANGUAGE 0
#endif

#define HELLO_EN "Hello, World!"
#define HELLO_ES "¡Hola, Mundo!"

const char* get_welcome_msg(void) {
#if LANGUAGE == 1
    return HELLO_EN;
#elif LANGUAGE == 2
    return HELLO_ES;
#elif LANGUAGE == 0

    fprintf(stderr, "Language is not defined, configure with: -DLANGUAGE=EN or -DLANGUAGE=ES.\n");
    exit(1);
#else
    fprintf(stderr, "Not a valid language value (%d). Onnly use EN or ES.\n", LANGUAGE);
    exit(1);
#endif
}
