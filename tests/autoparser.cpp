#include "../src/autoparser.h"
#include <gtest/gtest.h>
#include <absl/status/statusor.h>
#include <string>

using namespace std;

TEST(AutoparseTest, ParsesNoInput) {
  char *argv[] = {0};
  auto c = autoparse<Config>(1, argv, {}).value();
  EXPECT_EQ(c.single, false);
}

TEST(AutoparseTest, ParsesBooleanInput) {
  string arg1 = "--single";
  string arg2 = "true";
  vector<string> input_lines;
  char *argv[] = {arg1.data(), arg2.data(), 0};
  auto c = autoparse<Config>(3, argv, input_lines).value();

  EXPECT_EQ(c.single, true);
}

TEST(AutoparseTest, FailsOnInvalidBooleanValue) {
  string arg1 = "--single";
  string arg2 = "non-boolean-value";
  vector<string> input_lines;
  char *argv[] = {arg1.data(), arg2.data(), 0};
  auto c = autoparse<Config>(3, argv, input_lines);

  EXPECT_EQ(c.status().code(),absl::StatusCode::kInvalidArgument);
}

TEST(AutoparseTest, ParsesIntegerValue) {
  string arg1 = "--threads";
  string arg2 = "4";
  vector<string> input_lines;
  char *argv[] = {arg1.data(), arg2.data(), 0};
  auto c = autoparse<Config>(3, argv, input_lines);

  EXPECT_EQ(c.threads, 4);
}

TEST(AutoparseTest, FailsOnInvalidIntegerValue) {
  string arg1 = "--threads";
  string arg2 = "non-integer-value";
  vector<string> input_lines;
  char *argv[] = {arg1.data(), arg2.data(), 0};
  auto c = autoparse<Config>(3, argv, input_lines);

  EXPECT_EQ(c.status().code(),absl::StatusCode::kInvalidArgument);
}

TEST(AutoparseTest, FailsOnMissingValue) {
  string arg1 = "--threads";
  vector<string> input_lines;
  char *argv[] = {arg1.data(), 0};
  auto c = autoparse<Config>(2, argv, input_lines);

  EXPECT_EQ(c.status().code(),absl::StatusCode::kInvalidArgument);
}

TEST(AutoparseTest, ParsesMultiplInputFlags) {
  string arg1 = "--threads";
  string arg2 = "2";
  string arg3 = "--single";
  string arg4 = "true";
  vector<string> input_lines;
  char *argv[] = {arg1.data(), arg2.data(), arg3.data(), arg4.data(), 0};
  auto c = autoparse<Config>(5, argv, input_lines);

  EXPECT_EQ(c.single, true);
  EXPECT_EQ(c.threads, 2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
