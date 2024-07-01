#include "../src/autoparser.h"
#include <gtest/gtest.h>

struct Config {
  std::string name;
};

TEST(AutoparseTest, ParsesNoInput) {
  char *argv[] = {0};
  Config c = autoparse<Config>(1, argv, {});

  EXPECT_EQ(c.name, "Hello, World!");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
