#include <stdio.h>
#include <string.h>
#include "welcome.h"
#include "utest.h"   


UTEST(welcome, english) {
    const char* msg = get_welcome_msg();
    ASSERT_TRUE(strcmp(msg, "Hello, World!") == 0);
}

UTEST_MAIN()
