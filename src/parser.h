#include "config.h"
#include <absl/status/statusor.h>
#include <string>
#include <vector>


absl::StatusOr<Config> parse(int argc, char *argv[], std::vector<std::string> input_lines);

// TODO: Add `validate` method

// absl::StatusOr<Config> validate(Config c);