#include "parser.h"
#include <string>
#include <vector>

Config parse(int argc, char *argv[], std::vector<std::string> input_lines) {
  return Config(false, input_lines);
}
