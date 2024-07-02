#include <rfl.hpp>
#include <rfl/json.hpp>
#include <string>
#include <vector>
#include "config.h"

class Config;

template <typename T>
T autoparse(int argc, char *argv[], std::vector<std::string> input_lines);

