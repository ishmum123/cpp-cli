#pragma once
#include <string>
#include <vector>

using namespace std;

class Config {
public:
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
private:
    bool single;
    vector<string> lines;
};

inline Config::Config(){}

inline Config::Config(bool single, vector<string> lines)
    : single(single), lines(lines) {}
inline vector<string> Config::getLines() { return lines; }
inline bool Config::getIsSingle() const { return single; }
