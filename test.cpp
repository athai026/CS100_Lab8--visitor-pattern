#include "gtest/gtest.h"
#include "subTest.hpp"
#include "divTest.hpp"
#include "multTest.hpp"
#include "opTest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
