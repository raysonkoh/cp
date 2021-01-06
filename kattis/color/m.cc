#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int s, c, k;
  cin >> s >> c >> k;
  vector<int> v(s);
  for (int i = 0; i < s; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int currMin = -1;
  int res = 0;
  int capc = 0;
  for (int i = 0; i < s; i++) {
    if (i == 0) {
      currMin = v[i];
      capc++;
      res++;
    } else if (v[i] - currMin > k) {
      currMin = v[i];
      capc = 1;
      res++;
    } else {
      capc++;
      if (capc > c) {
        currMin = v[i];
        capc = 1;
        res++;
      }
    }
  }

  cout << res << "\n";
}