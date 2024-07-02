#pragma once
#include <string>
#include <vector>

using namespace std;

struct Config {
  Config();
  Config(bool, vector<string>);
  Config(Config &&) = default;
  Config(const Config &) = default;
  Config &operator=(Config &&) = default;
  Config &operator=(const Config &) = default;
  ~Config()=default;

  // Getters
  vector<string> getLines();
  bool getIsSingle() const;

  bool single;
  vector<string> lines;
};

inline Config::Config() : single(false), lines({}){}

inline Config::Config(bool single, vector<string> lines)
    : single(single), lines(lines) {}
inline vector<string> Config::getLines() { return lines; }
inline bool Config::getIsSingle() const { return single; }
