#include "parser.h"
#include "runner.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  Config c = parse(argc, argv);
  Result r = run(c);

  for (string line : r.getOutput())
    cout << line << endl;

  for (string line : r.getErrors())
    cerr << line << endl;

  return 0;
}
