#include "utest.h"
#include <string.h> // For strlen()

UTEST(strlen, basic) {
  ASSERT_EQ(strlen(""), 0);
  ASSERT_EQ(strlen("a"), 1);
  ASSERT_EQ(strlen("hello"), 5);
}
UTEST(strlen, spaces) {
  ASSERT_EQ(strlen("hello world"), 11);
  ASSERT_EQ(strlen("hello\tworld"), 11);
  ASSERT_EQ(strlen("hello\nworld"), 11);
}


UTEST_MAIN()
