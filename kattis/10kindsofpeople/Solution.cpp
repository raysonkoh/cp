#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> m;
  for (int i = 0; i < r; i++) {
    vector<int> tmp;
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      int k = s.at(j) - '0';
      tmp.push_back(k);
    }
    m.push_back(tmp);
  }

  int n;
  cin >> n;
  map<pair<int, int>, int> seen;
  int indx = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      // bfs from M[i][j]
      int val = m[i][j];
      pair<int, int> src;
      src.first = i;
      src.second = j;

      if (seen.find(src) != seen.end()) {
        continue;
      }

      queue<pair<int, int>> q;
      q.push(src);
      seen[src] = indx;

      while (q.size() > 0) {
        pair<int, int> next = q.front();
        q.pop();

        int currR = next.first;
        int currC = next.second;

        if (currR - 1 >= 0) {
          if (m[currR - 1][currC] == val) {
            pair<int, int> tmp;
            tmp.first = currR - 1;
            tmp.second = currC;
            if (seen.find(tmp) == seen.end()) {
              seen[tmp] = indx;
              q.push(tmp);
            }
          }
        }
        if (currR + 1 < r) {
          if (m[currR + 1][currC] == val) {
            pair<int, int> tmp;
            tmp.first = currR + 1;
            tmp.second = currC;
            if (seen.find(tmp) == seen.end()) {
              seen[tmp] = indx;
              q.push(tmp);
            }
          }
        }
        if (currC - 1 >= 0) {
          if (m[currR][currC - 1] == val) {
            pair<int, int> tmp;
            tmp.first = currR;
            tmp.second = currC - 1;
            if (seen.find(tmp) == seen.end()) {
              seen[tmp] = indx;
              q.push(tmp);
            }
          }
        }
        if (currC + 1 < c) {
          if (m[currR][currC + 1] == val) {
            pair<int, int> tmp;
            tmp.first = currR;
            tmp.second = currC + 1;
            if (seen.find(tmp) == seen.end()) {
              seen[tmp] = indx;
              q.push(tmp);
            }
          }
        }
      }
      indx++;
    }
  }

  for (int i = 0; i < n; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;

    int val = m[r1][c1];

    pair<int, int> initial;
    initial.first = r1;
    initial.second = c1;

    pair<int, int> dest;
    dest.first = r2;
    dest.second = c2;

    if (seen.find(initial)->second == seen.find(dest)->second) {
      if (val == 1) {
        cout << "decimal" << endl;
      } else {
        cout << "binary" << endl;
      }
    } else {
      cout << "neither" << endl;
    }
  }
  return 0;
}
