#include <gtest/gtest.h>
#include <lib.hpp>

TEST(LibTests, TestPlus)
{
  ASSERT_EQ(plus(3, 5), 8);
}

TEST(LibTests, TestMinus)
{
  ASSERT_EQ(minus(2, 3), -1);
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}