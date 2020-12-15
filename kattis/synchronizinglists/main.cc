#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> getcorrespond(vector<int> first, vector<int> second) {
  map<int, int> res;
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  for (int i = 0; i < first.size(); i++) {
    res[first[i]] = second[i];
  }
  return res;
}

int main() {
  int n;
  bool isfirst = true;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    if (isfirst) {
      isfirst = false;
    } else {
      cout << endl;
    }

    vector<int> first;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      first.push_back(x);
    }

    vector<int> second;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      second.push_back(x);
    }

    map<int, int> m = getcorrespond(first, second);
    for (int i = 0; i < n; i++) {
      cout << m[first[i]] << endl;
    }
  }
}
