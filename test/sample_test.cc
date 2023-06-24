// Copyright 2023 @saito
#include <gtest/gtest.h>

#include "../src/sample/sample.hh"


namespace SampleTest {
TEST(sum_unit_test, test_case1) {
  const int a = 3, b = 4;
  const int sum = Sample::sum(a, b);

  EXPECT_EQ(sum, 7);
}

TEST(sum_unit_test, test_case2) {
  const int a = 4, b = 4;
  const int sum = Sample::sum(a, b);

  EXPECT_EQ(sum, 8);
}
}  // namespace SampleTest
