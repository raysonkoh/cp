#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> tea;
  for (int i = 0; i < n; i++) {
    int ptea;
    cin >> ptea;
    tea.push_back(ptea);
  }
  int m;
  cin >> m;
  vector<int> topping;
  for (int i = 0; i < m; i++) {
    int ptop;
    cin >> ptop;
    topping.push_back(ptop);
  }
  int best = INT_MAX;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      best = min(best, tea[i] + topping[x - 1]);
    }
    // cout << "i: " << i << " val: " << tmpbest << endl;
  }
  int money;
  cin >> money;
  // cout << best << endl;
  int res = money / best;
  if (res == 0) {
    cout << 0 << endl;
  } else {
    cout << res - 1 << endl;
  }
}