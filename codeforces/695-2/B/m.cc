#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> s(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    int tol = 0;
    for (int i = 1; i < n - 1; i++) {
      if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
        s[i] = 1;
        tol++;
      } else if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
        s[i] = -1;
        tol++;
      }
    }

    int best = (s[0] != 0) || (s[n - 1] != 0);
    for (int i = 1; i < n - 1; i++) {
      int ph1 = v[i - 1];
      int tmp1 = (s[i] != 0) + (s[i - 1] != 0);

      if (s[i + 1] == 1) {
        if (v[i + 1] <= ph1)
          tmp1++;
      } else if (s[i + 1] == -1) {
        if (v[i + 1] >= ph1)
          tmp1++;
      } else if (i + 2 < n) {
        if (v[i + 1] > ph1 && v[i + 1] > v[i + 2])
          tmp1--;
        else if (v[i + 1] < ph1 && v[i + 1] < v[i + 2])
          tmp1--;
      }

      int ph2 = v[i + 1];
      int tmp2 = (s[i] != 0) + (s[i + 1] != 0);
      if (s[i - 1] == 1) {
        if (v[i - 1] <= ph2)
          tmp2++;
      } else if (s[i - 1] == -1) {
        if (v[i - 1] >= ph2)
          tmp2++;
      } else if (i - 2 >= 0) {
        if (v[i - 1] > ph2 && v[i - 1] > v[i - 2])
          tmp2--;
        else if (v[i - 1] < ph2 && v[i - 1] < v[i - 2])
          tmp2--;
      }

      best = max(best, max(tmp1, tmp2));
    }

    cout << max(tol - best, 0) << "\n";
  }
}
