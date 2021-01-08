#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int bestDay, best;
  for (int i = 0; i < n - 2; i++) {
    int tmp = max(v[i], v[i + 2]);
    if (i == 0) {
      best = tmp;
      bestDay = i + 1;
    } else if (tmp < best) {
      best = tmp;
      bestDay = i + 1;
    }
  }
  cout << bestDay << " " << best << '\n';
}