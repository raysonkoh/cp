#include <algorithm>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<string> v{
      "A",
      "A#",
      "B",
      "C",
      "C#",
      "D",
      "D#",
      "E",
      "F",
      "F#",
      "G",
      "G#"};
  vector<set<string>> sets(v.size());
  vector<int> jumps{2, 2, 1, 2, 2, 2, 1};
  for (int i = 0; i < v.size(); i++) {
    set<string> s;
    int tmp = i;
    for (int j : jumps) {
      s.insert(v[tmp]);
      tmp += j;
      tmp %= v.size();
    }
    s.insert(v[tmp]);
    sets[i] = s;
  }

  int n;
  cin >> n;
  set<string> in;
  while (n--) {
    string s;
    cin >> s;
    in.insert(s);
  }
  vector<string> res;
  for (int i = 0; i < sets.size(); i++) {
    bool can = true;
    for (auto x : in) {
      if (sets[i].count(x) == 0) {
        can = false;
        break;
      }
    }
    if (can)
      res.push_back(v[i]);
  }
  if (res.size() == 0)
    cout << "none";
  else
    for (auto x : res)
      cout << x << " ";
  cout << '\n';
}
