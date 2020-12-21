#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int res = 0;
  vector<int> h(1000001, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    if (h[x + 1] > 0) {
      h[x]++;
      h[x + 1]--;
    } else {
      h[x]++;
      res++;
    }
  }
  cout << res << endl;
}