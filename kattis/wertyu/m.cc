#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<char> v1{'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='};
  vector<char> v2{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'};
  vector<char> v3{'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''};
  vector<char> v4{'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'};
  vector<vector<char>> v;
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);
  auto findPrev = [](char ch, vector<char> &ve) {
    auto it = find(ve.begin(), ve.end(), ch);
    if (it == ve.end())
      return ' ';
    return *prev(it);
  };

  string s;
  while (getline(cin, s)) {
    for (char c : s) {
      if (c == ' ') {
        cout << c;
        continue;
      }

      for (int i = 0; i < 4; i++) {
        char ch = findPrev(c, v[i]);
        if (ch == ' ')
          continue;
        else
          cout << ch;
      }
    }
    cout << '\n';
  }
}
