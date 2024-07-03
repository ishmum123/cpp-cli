#include "runner.h"
#include "absl/strings/str_join.h"
#include <absl/status/status.h>
#include <absl/status/statusor.h>
#include <string>
#include <vector>

using namespace std;

absl::StatusOr<vector<string>> run(Config c) {
  string s = absl::StrJoin(c.lines, ",");
  vector<string> v = {s};
  return v;
};
