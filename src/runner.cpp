#include "runner.h"
#include "absl/strings/str_join.h"
#include <absl/status/status.h>
#include <absl/status/statusor.h>
#include <string>
#include <vector>

using namespace std;

absl::StatusOr<vector<string>> run(absl::StatusOr<Config> c) {
  string s = absl::StrJoin(c->getLines(), ",");
  vector<string> v = {s};
  return static_cast<absl::StatusOr<vector<string>>>(v);
};
