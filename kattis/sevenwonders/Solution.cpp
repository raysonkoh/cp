#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  v.push_back(0);
  v.push_back(0);
  v.push_back(0);
  string s;
  cin >> s;
  // 0 - T, 1 - C, 2 - G
  for (int i = 0; i < s.length(); i++) {
    char c = s.at(i);
    if (c == 'T') {
      v[0]++;
    } else if (c == 'C') {
      v[1]++;
    } else {
      v[2]++;
    }
  }

  int res = 0;
  int numSet = INT_MAX;
  for (int i = 0; i < v.size(); i++) {
    numSet = min(numSet, v[i]);
    res += v[i] * v[i];
  }
  res += numSet * 7;
  cout << res << endl;
  return 0;
}