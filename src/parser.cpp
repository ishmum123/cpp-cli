#include "parser.h"
#include <string>
#include <vector>

absl::StatusOr<Config> parse(int argc, char *argv[], std::vector<std::string> input_lines) {
    Config c = Config(false, input_lines);
    return validate(c);
}

absl::StatusOr<Config> validate(Config c){
    return static_cast<absl::StatusOr<Config>>(c);
}