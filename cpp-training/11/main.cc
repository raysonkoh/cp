#include <iostream>
#include <map>

using namespace std;

int main() {
  map<string, int> m;
  m["abc"] = 1;
  m["def"] = 2;
  for (auto [key, value] : m) {
    cout << key << " = " << value << endl;
  }
}