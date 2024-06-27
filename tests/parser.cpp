#include "../src/parser.h"
#include <gtest/gtest.h>
#include <string>

TEST(ParseTest, ParsesNoInput) {
  char *argv[] = {0};
  Config c = parse(1, argv, {});

  EXPECT_EQ(c.getIsSingle(), false);
  EXPECT_EQ(c.getLines().size(), 0);
}

TEST(ParseTest, ParsesSimpleInput) {
  string arg1 = "--simple";
  string arg2 = "true";
  char *argv[] = {arg1.data(), arg2.data(), 0};
  Config c = parse(3, argv, {});

  EXPECT_EQ(c.getIsSingle(), true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
