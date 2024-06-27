#include "config.h"
#include <absl/status/statusor.h>
#include <string>
#include <vector>

using namespace std;

absl::StatusOr<vector<string>> run(Config c);
