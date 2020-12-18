#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<bool> prime(n + 1, true);
  prime[0] = false;
  prime[1] = false;

  int res = 0;
  for (int i = 2; i <= sqrt(n + 1); i++) {
    if (prime[i]) {
      res++;
      for (int j = i * i; j < n + 1; j += i) {
        prime[j] = false;
      }
    }
  }

  for (int i = sqrt(n + 1) + 1; i < n + 1; i++) {
    if (prime[i]) {
      res++;
    }
  }

  cout << res << endl;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    cout << prime[x] << endl;
  }
}