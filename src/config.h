#pragma once
#include <string>
#include <vector>

using namespace std;

struct Config {
  bool single;
  int thread;
  vector<string> lines;
};
