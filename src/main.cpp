#include "absl/status/statusor.h"
#include "autoparser.h"
#include "runner.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  vector<string> lines;
  for (string line; getline(cin, line);)
    lines.push_back(line);

  auto c = autoparse<Config>(argc, argv, lines);
  absl::StatusOr<vector<string>> result = run(c.value());

  if (result.ok()) {
    for (string line : result.value())
      cout << line << endl;
  } else {
    cerr << result.status() << endl;
  }

  return 0;
}
