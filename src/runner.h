#include "config.h"
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

// TODO: Use `abseil`
class Result {
public:
  Result(vector<string>, vector<string>);
  Result(Result &&) = default;
  Result(const Result &) = default;
  Result &operator=(Result &&) = default;
  Result &operator=(const Result &) = default;
  ~Result();
  vector<string> getOutput();
  vector<string> getErrors();

private:
  vector<string> output;
  vector<string> errors;
};

inline Result::Result(vector<string> output, vector<string> errors)
    : output(output), errors(errors) {}

inline Result::~Result() {}
inline vector<string> Result::getOutput() { return output; }
inline vector<string> Result::getErrors() { return errors; }

Result run(Config c);
