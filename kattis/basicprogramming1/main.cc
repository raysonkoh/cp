#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = x;
  }
  switch (t) {
  case 1: {
    cout << 7 << endl;
    break;
  }
  case 2: {
    if (v[0] > v[1]) {
      cout << "Bigger" << endl;
    } else if (v[0] == v[1]) {
      cout << "Equal" << endl;
    } else {
      cout << "Smaller" << endl;
    }
    break;
  }
  case 3: {
    vector<int> tmp(3);
    for (int i = 0; i < 3; i++) {
      tmp[i] = v[i];
    }
    sort(tmp.begin(), tmp.end());
    cout << tmp[1] << endl;
    break;
  }
  case 4: {
    long long res = 0;
    for (int i = 0; i < v.size(); i++) {
      res += v[i];
    }
    cout << res << endl;
    break;
  }
  case 5: {
    long long resll = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] % 2 == 0) {
        resll += v[i];
      }
    }
    cout << resll << endl;
    break;
  }
  case 6: {
    for (int i = 0; i < v.size(); i++) {
      int x = v[i] % 26;
      char c = (char)(x + 97);
      cout << c;
    }
    cout << endl;
    break;
  }
  case 7: {
    set<int> seen;
    int curr = 0;
    while (true) {
      if (seen.find(curr) != seen.end()) {
        cout << "Cyclic" << endl;
        break;
      }

      if (curr < 0 || curr > n - 1) {
        cout << "Out" << endl;
        break;
      } else if (curr == n - 1) {
        cout << "Done" << endl;
        break;
      }

      seen.insert(curr);
      curr = v[curr];
    }
    break;
  }
  }
}