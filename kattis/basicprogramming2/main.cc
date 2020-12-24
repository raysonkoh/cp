#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  vector<int> r;
  map<int, int> count;
  bool sumTo7777 = false;
  bool isUnique = true;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (count.find(7777 - v[i]) != count.end()) {
      sumTo7777 = true;
    }
    if (count.find(v[i]) == count.end()) {
      count[v[i]] = 0;
    } else {
      isUnique = false;
    }
    count[v[i]]++;
    if (v[i] >= 100 && v[i] <= 999) {
      r.push_back(v[i]);
    }
  }
  switch (t) {
  case 1: {
    cout << (sumTo7777 ? "Yes" : "No") << endl;
    break;
  }
  case 2: {
    cout << (isUnique ? "Unique" : "Contains duplicate") << endl;
    break;
  }
  case 3: {
    for (auto it : count) {
      int key = it.first;
      int val = it.second;
      if (val > n / 2) {
        cout << key << endl;
        return 0;
      }
    }
    cout << -1 << endl;
    break;
  }
  case 4: {
    sort(v.begin(), v.end());
    if (v.size() % 2 == 0) {
      cout << v[(v.size() / 2) - 1] << " " << v[v.size() / 2] << endl;
    } else {
      cout << v[v.size() / 2] << endl;
    }
    break;
  }
  case 5: {
    sort(r.begin(), r.end());
    for (int i = 0; i < r.size(); i++) {
      if (i == 0) {
        cout << r[i];
      } else {
        cout << " " << r[i];
      }
    }
    cout << endl;
    break;
  }
  }
}