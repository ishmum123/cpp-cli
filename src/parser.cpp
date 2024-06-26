#include "parser.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Config parse(int argc, char *argv[]) {
  vector<string> lines;
  for (string line; getline(cin, line);)
    lines.push_back(line);
  return Config(false, lines);
}
