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
  int n;
  cin >> n;
  vector<char> v(n - 1);
  for (int i = 0; i < n - 1; i++)
    cin >> v[i];

  deque<pair<char, int>> freq;
  for (int i = 0; i < n - 1; i++) {
    if (freq.size() == 0) {
      freq.push_back({v[i], 1});
    } else if (freq.back().first == v[i]) {
      freq.back().second++;
    } else {
      freq.push_back({v[i], 1});
    }
  }

  set<int> possible;
  for (int i = 0; i < n; i++)
    possible.insert(i + 1);

  /*
  for (auto [c, ct] : freq)
    cout << c << " " << ct << '\n';
  cout << endl;
  */

  // L: {min...max - 1}
  // R: {min + 1...max}
  vector<int> res(n);
  int indx = n - 1;
  for (int i = freq.size() - 1; i >= 0; i--) {
    auto [c, ct] = freq[i];
    int origIndx = indx;
    if (c == 'R') {
      // start from back to front
      for (int j = 0; j < ct; j++) {
        auto it = prev(possible.end());
        // cout << "R extracted: " << *it << endl;
        res[indx] = *it;
        possible.erase(it);
        indx--;
      }
    } else {
      // from front to back
      indx = indx - ct + 1;
      for (int j = 0; j < ct; j++) {
        auto it = prev(possible.end());
        it = prev(it);
        // cout << "L extracted: " << *it << endl;
        res[indx] = *it;
        possible.erase(it);
        indx++;
      }
    }
    indx = origIndx - ct;
  }

  assert(possible.size() == 1);
  res[0] = *possible.begin();
  for (auto x : res)
    cout << x << '\n';
}
