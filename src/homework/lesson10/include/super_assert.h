#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SUPER_ASSERT_TRACE
  #define SUPER_ASSERT_TRACE 0
#endif
#ifndef SUPER_ASSERT_PERMISSIVE
  #define SUPER_ASSERT_PERMISSIVE 0
#endif
#ifndef SUPER_ASSERT_VERBOSE
  #define SUPER_ASSERT_VERBOSE 0
#endif

#define __BASEFILE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifdef NDEBUG
  #define super_assert(cond, msg) do { (void)sizeof(cond); } while(0)
#else
  #define super_assert(cond, msg)                                                   \
    do {                                                                            \
      int __ok = !!(cond);                                                          \
      if (SUPER_ASSERT_TRACE || !__ok) {                                            \
        if (SUPER_ASSERT_VERBOSE) {                                                 \
          fprintf(stderr,                                                           \
            "[super_assert] %s:%d:%s(): %s: %s\n",                                  \
            __BASEFILE__, __LINE__, __func__, (__ok ? "PASS" : "FAIL"), (msg));     \
        } else {                                                                    \
          fprintf(stderr, "[super_assert] %s: %s\n",                                \
                  (__ok ? "PASS" : "FAIL"), (msg));                                 \
        }                                                                           \
      }                                                                             \
      if (!__ok) {                                                                  \
        if (SUPER_ASSERT_PERMISSIVE) {                                              \                                                           \
        } else {                                                                    \
          abort();                                                                  \
        }                                                                           \
      }                                                                             \
    } while(0)
#endif
