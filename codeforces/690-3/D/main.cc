#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
}

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
    int tolSum = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      tolSum += v[i];
    }

    int res;
    for (int k = n; k >= 1; k--) {
      int numOps = n - k;
      if (tolSum % k == 0) {
        // is a divisor, check whether can split
        int expected = tolSum / k;
        int tmpSum = 0;
        int ct = 0;
        for (int i = 0; i < n; i++) {
          tmpSum += v[i];
          if (tmpSum == expected) {
            tmpSum = 0;
            ct++;
          } else if (tmpSum > expected) {
            break;
          }
        }
        if (ct == k) {
          // cannot split evenly
          res = numOps;
          break;
        }
      }
    }
    cout << res << "\n";
  }
}