#include <iostream>
#include <map>
#include <vector>

using namespace std;

void printvect(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

bool istriangle(vector<int> &neis, vector<vector<int>> &m) {
  for (int i = 0; i < neis.size(); i++) {
    for (int j = i + 1; j < neis.size(); j++) {
      if (m[neis[i]][neis[j]] == 1) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int n;
  while (cin >> n) {
    if (n == -1) {
      break;
    }

    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
      vector<int> tmp;
      m[i] = tmp;
    }

    vector<vector<int>> M;
    for (int i = 0; i < n; i++) {
      vector<int> tmp;
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        if (x == 1) {
          m[i].push_back(j);
        }
        tmp.push_back(x);
      }
      M.push_back(tmp);
    }

    bool isfirst = true;
    for (int i = 0; i < n; i++) {
      vector<int> neis = m[i];
      if (!istriangle(neis, M)) {
        if (isfirst) {
          isfirst = false;
        } else {
          cout << " ";
        }
        cout << i;
      }
    }
    cout << endl;
  }
}
