#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> lines;

  for (string line; getline(cin, line);)
    lines.push_back(line);
  for (string line : lines)
    cout << line << endl;

  if (lines.size() == 0)
    cout << "Please provide a file" << endl;

  return 0;
}
