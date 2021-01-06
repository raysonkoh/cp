#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> parent(30001); // (prev S, indx of item)
  vector<long long> v(30001, 0);
  // vector<pair<int, int>> parent(15); // (prev S, indx of item)
  // vector<int> v(15, 0);
  parent[0] = {-1, -1};
  for (int i = 0; i < n; i++) {
    // cout << "i: " << i << endl;
    int x;
    cin >> x;
    for (int j = 1; j < v.size(); j++) {
      if (j % x == 0) {
        // cout << "1 incr " << j << endl;
        if (j == x) {
          v[j]++;
          parent[j] = {0, i};
        } else {
          v[j] += v[j - x];
          parent[j] = {j - x, i};
        }
      } else if (v[j] && j + x < v.size()) {
        // cout << "2 incr " << j + x << " from: " << j << endl;
        v[j + x] += v[j];
        parent[j + x] = {j, i};
      }
    }
  }

  /*
  for (int i = 1; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;

  for (int i = 1; i < v.size(); i++) {
    cout << "(" << parent[i].first << ", " << parent[i].second << ") ";
  }
  cout << endl;
  */

  int m;
  cin >> m;
  while (m--) {
    int s;
    cin >> s;
    if (v[s] == 0)
      cout << "Impossible\n";
    else if (v[s] > 1)
      cout << "Ambiguous\n";
    else {
      pair<int, int> p = parent[s];
      vector<int> res;
      while (p.first != -1) {
        res.push_back(p.second);
        p = parent[p.first];
      }
      sort(res.begin(), res.end());
      bool isFirst = true;
      for (int i : res) {
        if (isFirst)
          isFirst = false;
        else
          cout << " ";
        cout << i + 1;
      }
      cout << "\n";
    }
  }
}