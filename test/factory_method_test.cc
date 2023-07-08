// Copyright 2023 saito
#include "../src/factory_method/factory_method.hh"
#include <gtest/gtest.h>

TEST(factory_method, sum_test) {
  EXPECT_EQ(3, factory_method::sum(1, 2));
}
