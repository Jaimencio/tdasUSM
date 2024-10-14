#include <cassert>
#include <iostream>

using namespace std;

bool Assert(const bool assertion, const char* message) {
  if (!assertion) {
    cout << message << endl;
  }
  return assertion;
}