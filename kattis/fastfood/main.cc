#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long calc(vector<int> &stickers, vector<int> &v) {
  int count = 1;
  while (true) {
    bool canMinus = true;
    for (int i = 0; i < v.size(); i++) {
      int x = v[i];
      x--;
      if (stickers[x] - count < 0) {
        canMinus = false;
        count--;
        break;
      }
    }
    if (canMinus) {
      count++;
    } else {
      break;
    }
  }

  for (int i = 0; i < v.size(); i++) {
    int x = v[i];
    x--;
    stickers[x] -= count;
  }
  return count;
}

void printVect(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, vector<int>>> v(n);
    for (int j = 0; j < n; j++) {
      int k;
      cin >> k;
      vector<int> tmp;
      for (int l = 0; l < k; l++) {
        int x;
        cin >> x;
        tmp.push_back(x);
      }
      int price;
      cin >> price;
      v[j] = make_pair(price, tmp);
      // cout << "j: " << j << " : ";
      // printVect(tmp);
    }

    vector<int> stickers(m, 0);
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      stickers[i] = x;
    }
    // cout << "stickers : ";
    // printVect(stickers);

    sort(v.rbegin(), v.rend());
    long res = 0;
    for (int i = 0; i < v.size(); i++) {
      pair<int, vector<int>> p = v[i];
      int count = calc(stickers, p.second);
      res += count * p.first;
    }
    cout << res << endl;
  }
}