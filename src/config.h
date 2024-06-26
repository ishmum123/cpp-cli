#pragma once
#include <string>
#include <vector>

using namespace std;

class Config {
public:
  Config(bool, vector<string>);
  Config(Config &&) = default;
  Config(const Config &) = default;
  Config &operator=(Config &&) = default;
  Config &operator=(const Config &) = default;
  ~Config();

  // Getters
  vector<string> getLines();
  bool getIsSingle();

private:
  bool single;
  vector<string> lines;
};

inline Config::Config(bool single, vector<string> lines)
    : single(single), lines(lines) {}

inline Config::~Config() {}

inline vector<string> Config::getLines() { return lines; }
inline bool Config::getIsSingle() { return single; }
