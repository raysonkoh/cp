#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> countBits(string s) {
  int countZero = 0;
  int countOne = 0;
  for (int i = 0; i < s.length(); i++) {
    char c = s.at(i);
    if (c == '0') {
      countZero++;
    } else if (c == '1') {
      countOne++;
    }
  }
  return make_pair(countZero, countOne);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int c;
  cin >> c;
  for (int i = 0; i < c; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Case " << i + 1 << ": ";

    pair<int, int> p1 = countBits(s1);
    pair<int, int> p2 = countBits(s2);

    if (p1.second > p2.second) {
      cout << -1 << endl;
      continue;
    }

    int excessOne = p2.second - p1.second;
    // cout << "excessOne: " << excessOne << endl;
    int res = 0;
    int swaps = 0;
    // settle '?'
    for (int i = 0; i < s1.length(); i++) {
      char c1 = s1.at(i);
      if (c1 == '?') {
        res++;
        char c2 = s2.at(i);
        if (c2 == '0') {
          s1[i] = '0';
        } else if (excessOne == 0) {
          s1[i] = '0';
        } else {
          s1[i] = '1';
          excessOne--;
        }
      }
    }
    // cout << "after ?: " << s1 << endl;
    // cout << "excessOne: " << excessOne << endl;

    // settle '0' -> '1'
    for (int i = 0; i < s1.length(); i++) {
      char c1 = s1.at(i);
      if (c1 == '0') {
        char c2 = s2.at(i);
        if (c2 == '1' && excessOne > 0) {
          res++;
          s1[i] = '1';
          excessOne--;
        }
      }
    }
    // cout << "after 0->1: " << s1 << endl;

    // settle swaps
    for (int i = 0; i < s1.length(); i++) {
      char c1 = s1.at(i);
      char c2 = s2.at(i);
      if (c1 != c2) {
        swaps++;
      }
    }
    // cout << "after swaps: " << s1 << endl;

    // cout << "swaps: " << swaps << endl;
    cout << res + swaps / 2 << endl;
  }
}