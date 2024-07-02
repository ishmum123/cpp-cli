#include "../src/autoparser.h"
#include <gtest/gtest.h>
#include <string>

TEST(AutoparseTest, ParsesNoInput) {
  char *argv[] = {0};
  const auto &c = autoparse<Config>(1, argv, {});
  EXPECT_EQ(c.getIsSingle(), false);
}

TEST(AutoparseTest, ParsesSimpleInput) {
  std::string arg1 = "--single";
  std::string arg2 = "true";
  std::vector<std::string> input_lines;
  input_lines.push_back("Hello World");
  char *argv[] = {arg1.data(), arg2.data(), 0};
  Config c = autoparse<Config>(3, argv, input_lines);

  EXPECT_EQ(c.getIsSingle(), true);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
