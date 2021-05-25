#include "gtest/gtest.h"

#include "addTest.hpp"
#include "subTest.hpp"
#include "divTest.hpp"
#include "opTest.hpp"
#include "multTest.hpp"
#include "powTest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
