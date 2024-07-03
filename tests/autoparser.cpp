#include "../src/autoparser.h"
#include <gtest/gtest.h>
#include <absl/status/statusor.h>
#include <string>

TEST(AutoparseTest, ParsesNoInput) {
  char *argv[] = {0};
  auto c = autoparse<Config>(1, argv, {}).value();
  EXPECT_EQ(c.single, false);
}

TEST(AutoparseTest, ParsesSingleInputTrue) {
  std::string arg1 = "--single";
  std::string arg2 = "true";
  std::vector<std::string> input_lines;
  char *argv[] = {arg1.data(), arg2.data(), 0};
  auto c = autoparse<Config>(3, argv, input_lines).value();

  EXPECT_EQ(c.single, true);
}

TEST(AutoparseTest, ParsesSingleInputFalse) {
  std::string arg1 = "--single";
  std::string arg2 = "false";
  std::vector<std::string> input_lines;
  char *argv[] = {arg1.data(), arg2.data(), 0};
  auto c = autoparse<Config>(3, argv, input_lines).value();

  EXPECT_EQ(c.single, false);
}

TEST(AutoparseTest, ParsesSingleInputNonBooleanValue) {
  std::string arg1 = "--single";
  std::string arg2 = "non-boolean-value";
  std::vector<std::string> input_lines;
  char *argv[] = {arg1.data(), arg2.data(), 0};
  auto c = autoparse<Config>(3, argv, input_lines);

  EXPECT_EQ(c.status().code(),absl::StatusCode::kInvalidArgument);
}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
