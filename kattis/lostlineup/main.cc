#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<int, int> m;
  vector<int> v;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
    m[x] = i;
  }
  sort(v.begin(), v.end());
  cout << 1 << " ";
  for (int i = 0; i < v.size(); i++) {
    if (i == v.size() - 1) {
      cout << m[v[i]];
    } else {
      cout << m[v[i]] << " ";
    }
  }
  cout << endl;
}