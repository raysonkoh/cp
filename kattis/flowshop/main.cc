#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      v[i][j] = x;
    }
  }
  // (first, second) -> (endtime, label of node)
  auto cmp = [](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first > b.first;
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> currPq(
      cmp);
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> nextPq(
      cmp);
  int stage = 0;
  for (int i = 0; i < n; i++) {
    currPq.push(make_pair(0, i));
  }
  while (stage < m) {
    int currTime = 0;
    for (int i = 0; i < n; i++) {
      pair<int, int> p = currPq.top();
      pair<int, int> newPair =
          make_pair(max(currTime, p.first) + v[p.second][stage], p.second);
      currTime = max(currTime, newPair.first);
      // cout << "p.first: " << p.first << " p.second: " << p.second << endl;
      // cout << "newp.first: " << newPair.first
      //     << " newp.second: " << newPair.second << endl;
      currPq.pop();
      nextPq.push(newPair);
    }
    for (int i = 0; i < n; i++) {
      pair<int, int> p = nextPq.top();
      currPq.push(p);
      nextPq.pop();
    }
    stage++;
  }
  vector<int> res(n, 0);
  for (int i = 0; i < n; i++) {
    pair<int, int> p = currPq.top();
    currPq.pop();
    res[p.second] = p.first;
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << res[i];
    } else {
      cout << " " << res[i];
    }
  }
  cout << endl;
  /*
  for (int i = 0; i < n; i++) {
    cout << currPq.top().first << " " << currPq.top().second << endl;
    currPq.pop();
  }
  */
}