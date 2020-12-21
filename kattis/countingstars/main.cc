#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void print2d(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  int casenum = 1;
  while (cin >> n >> m) {
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c == '-') {
          v[i][j] = 1;
        }
      }
    }
    set<pair<int, int>> seen;
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        pair<int, int> p = make_pair(i, j);
        if (v[i][j] == 1 && seen.find(p) == seen.end()) {
          // cout << "i: " << i << " j: " << j << endl;
          res++;
          queue<pair<int, int>> q;
          q.push(p);
          seen.insert(p);
          while (q.size() > 0) {
            pair<int, int> p = q.front();
            q.pop();

            pair<int, int> next;
            if (p.first - 1 >= 0 && v[p.first - 1][p.second] == 1) {
              next = make_pair(p.first - 1, p.second);
              if (seen.find(next) == seen.end()) {
                seen.insert(next);
                q.push(next);
              }
            }

            if (p.first + 1 < n && v[p.first + 1][p.second] == 1) {
              next = make_pair(p.first + 1, p.second);
              if (seen.find(next) == seen.end()) {
                seen.insert(next);
                q.push(next);
              }
            }

            if (p.second - 1 >= 0 && v[p.first][p.second - 1] == 1) {
              next = make_pair(p.first, p.second - 1);
              if (seen.find(next) == seen.end()) {
                seen.insert(next);
                q.push(next);
              }
            }

            if (p.second + 1 < m && v[p.first][p.second + 1] == 1) {
              next = make_pair(p.first, p.second + 1);
              if (seen.find(next) == seen.end()) {
                seen.insert(next);
                q.push(next);
              }
            }
          }
        }
      }
    }
    cout << "Case " << casenum << ": " << res << endl;
    casenum++;
  }
}