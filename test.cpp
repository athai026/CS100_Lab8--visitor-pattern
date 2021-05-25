#include "gtest/gtest.h"
#include "addTest.hpp"
#include "multTest.hpp"
#include "powTest.hpp"
#include "subTest.hpp"
#include "divTest.hpp"
#include "powTest.hpp"
#include "opTest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
