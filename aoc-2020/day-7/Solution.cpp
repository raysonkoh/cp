#include <iostream>
#include <map>
#include <vector>

using namespace std;

int getIndx(string s) { if (s == '') }

int main() {
  map<int, vector<int>> m;
  for (int i = 1; i <= 9; i++) {
    vector<int> tmp;
    m[i] = tmp;
  }
  m[1].push_back(3);
  m[1].push_back(4);

  m[2].push_back(3);
  m[2].push_back(4);

  m[3].push_back(5);

  m[4].push_back(5);
  m[4].push_back(8);

  m[5].push_back(6);
  m[5].push_back(7);

  m[6].push_back(8);
  m[6].push_back(9);

  m[7].push_back(8);
  m[7].push_back(9);
  return 0;
}