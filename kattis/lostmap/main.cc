#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    long long minWt = -1;
    int bestIndx = -1;
    for (int j = 0; j < n; j++) {
      long long x;
      cin >> x;
      if ((minWt == -1 || x < minWt) && (j != i)) {
        minWt = x;
        bestIndx = j;
      }
      // cout << "x: " << x << " minWt: " << minWt << endl;
    }
    int a = i;
    int b = bestIndx;
    // cout << "i: " << i << " a: " << a << " b: " << b << " minWt: " << minWt
    //     << endl;
    if (a > b) {
      swap(a, b);
    }
    pair<int, int> p = make_pair(a, b);
    if (s.find(p) == s.end()) {
      s.insert(p);
      cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
  }
}