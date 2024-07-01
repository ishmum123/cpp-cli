#include <rfl.hpp>
#include <rfl/json.hpp>
#include <string>
#include <vector>

template <typename T>

T autoparse(int argc, char *argv[], std::vector<std::string> input_lines) {
  return rfl::json::read<T>("").value();
}
