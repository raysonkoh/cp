#include <iostream>
#include <map>
#include <queue>
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
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      int xint = x - '0';
      v[i][j] = xint;
    }
  }

  // print2d(v);

  // step 1: convert all island / lakes to land
  map<int, bool> compIsSeaMap; // T if is indeed sea, else F
  vector<vector<int>> compVect(n, vector<int>(m, -1));
  int currComp = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = v[i][j];
      if (compVect[i][j] != -1 || x == 1) {
        continue;
      }

      pair<int, int> p = make_pair(i, j);
      // do bfs to find connectivity to edge of map
      queue<pair<int, int>> q;
      compVect[i][j] = currComp;
      q.push(p);
      bool canReachEdge = false;
      while (q.size() > 0) {
        pair<int, int> next = q.front();
        int f = next.first;
        int s = next.second;
        q.pop();

        if (f == 0 || f == n - 1 || s == 0 || s == m - 1) {
          canReachEdge = true;
        }
        if (f - 1 >= 0 && v[f - 1][s] == 0 && compVect[f - 1][s] == -1) {
          compVect[f - 1][s] = currComp;
          q.push(make_pair(f - 1, s));
        }
        if (f + 1 < n && v[f + 1][s] == 0 && compVect[f + 1][s] == -1) {
          compVect[f + 1][s] = currComp;
          q.push(make_pair(f + 1, s));
        }
        if (s - 1 >= 0 && v[f][s - 1] == 0 && compVect[f][s - 1] == -1) {
          compVect[f][s - 1] = currComp;
          q.push(make_pair(f, s - 1));
        }
        if (s + 1 < m && v[f][s + 1] == 0 && compVect[f][s + 1] == -1) {
          compVect[f][s + 1] = currComp;
          q.push(make_pair(f, s + 1));
        }
      }
      compIsSeaMap[currComp] = canReachEdge;
      currComp++;
    }
  }

  // print2d(compVect);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int comp = compVect[i][j];
      if (comp != -1 && (!compIsSeaMap[comp])) {
        v[i][j] = 1;
      }
    }
  }

  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = v[i][j];
      if (x == 1) {
        if (i - 1 < 0) {
          res++;
        }
        if (i + 1 >= n) {
          res++;
        }
        if (j - 1 < 0) {
          res++;
        }
        if (j + 1 >= m) {
          res++;
        }
      } else {
        if (i - 1 >= 0 && v[i - 1][j] == 1) {
          // cout << "add up edge, "
          //     << "i: " << i << " j: " << j << endl;
          res++;
        }
        if (i + 1 < n && v[i + 1][j] == 1) {
          // cout << "add below edge, "
          //     << "i: " << i << " j: " << j << endl;
          res++;
        }
        if (j - 1 >= 0 && v[i][j - 1] == 1) {
          // cout << "add left edge, "
          //     << "i: " << i << " j: " << j << endl;
          res++;
        }
        if (j + 1 < m && v[i][j + 1] == 1) {
          // cout << "add right edge, "
          //     << "i: " << i << " j: " << j << endl;
          res++;
        }
      }
    }
  }
  cout << res << endl;
}