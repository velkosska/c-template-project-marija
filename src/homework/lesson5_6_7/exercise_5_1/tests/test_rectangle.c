#include "utest.h"
#include "rectangle.h"

UTEST(rectangle, area_basic) {
    Rectangle r = {4, 5};
    ASSERT_EQ(area(r), 20);
}

UTEST(rectangle, grow_positive) {
    Rectangle r = {2, 3};
    grow(&r, 3, 2);
    ASSERT_EQ(r.width, 5);
    ASSERT_EQ(r.height, 5);
    ASSERT_EQ(area(r), 25);
}

UTEST(rectangle, grow_negative_clamp) {
    Rectangle r = {3, 3};
    grow(&r, -10, -1);
    ASSERT_EQ(r.width, 0);
    ASSERT_EQ(r.height, 2);
    ASSERT_EQ(area(r), 0);
}

UTEST_MAIN();
