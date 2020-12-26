#include <iostream>
#include <set>
#include <vector>

using namespace std;

void printset(set<long long> &s) {
  for (auto it : s) {
    cout << it << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  int caseNum = 1;
  while (cin >> n) {
    set<long long> s;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v[i] = x;
      for (int j = 0; j < i; j++) {
        s.insert(v[j] + v[i]);
      }
    }
    int m;
    cin >> m;
    cout << "Case " << caseNum << ":\n";
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      cout << "Closest sum to " << x << " is ";
      auto it = s.lower_bound(x);
      if (it == s.begin()) {
        cout << *it << ".\n";
      } else {
        int grtOrEq = *it;
        it--;
        int lessOrEq = *it;
        if (abs(x - lessOrEq) < abs(x - grtOrEq)) {
          cout << lessOrEq << ".\n";
        } else {
          cout << grtOrEq << ".\n";
        }
      }
    }
    caseNum++;
  }
}