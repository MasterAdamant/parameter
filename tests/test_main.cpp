#include <gtest/gtest.h>
#include "parameter.hpp"

template<typename T>
T processValue(T value)
{
    Parameter p {value};
    return p.getValueAs<T>();
}

TEST(BasicTypes, CharTests) {
    EXPECT_EQ('a', processValue('a'));
    EXPECT_STREQ("abc", processValue("abc"));
    EXPECT_EQ(0, processValue(0));
}
TEST(BasicTypes, IntTests) {
    EXPECT_EQ(1, processValue(1));
    EXPECT_EQ(-1, processValue(-1));
    EXPECT_EQ(0, processValue(0));
}
TEST(BasicTypes, FloatTests) {
    EXPECT_FLOAT_EQ(1.1f, processValue(1.1f));
    EXPECT_FLOAT_EQ(-1.1f, processValue(-1.1f));
}
TEST(BasicTypes, DoubleTests) {
    EXPECT_DOUBLE_EQ(1.1, processValue(1.1));
    EXPECT_DOUBLE_EQ(-1.1, processValue(-1.1));
}
TEST(BasicTypes, BooleanTests) {
    EXPECT_EQ(true, processValue(true));
    EXPECT_EQ(false, processValue(false));
}