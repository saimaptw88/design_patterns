// Copyright 2023 saito
#include "../src/mod/mod.hh"
#include <gtest/gtest.h>

TEST(mod, sum_test) {
  EXPECT_EQ(3, mod::sum(1, 2));
}
