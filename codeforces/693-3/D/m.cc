#include <algorithm>
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
    vector<long long> odd;
    vector<long long> even;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (x % 2 == 0)
        even.push_back(x);
      else
        odd.push_back(x);
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    int i = 0;
    int j = 0;
    long long as = 0;
    long long bs = 0;
    bool isAliceTurn = true;
    while (i < odd.size() && j < even.size()) {
      if (isAliceTurn) {
        if (even[j] >= odd[i]) {
          as += even[j];
          j++;
        } else {
          i++;
        }
      } else {
        if (odd[i] >= even[j]) {
          bs += odd[i];
          i++;
        } else {
          j++;
        }
      }

      isAliceTurn = !isAliceTurn;
    }

    while (i < odd.size()) {
      if (!isAliceTurn) {
        bs += odd[i];
      }
      i++;
      isAliceTurn = !isAliceTurn;
    }

    while (j < even.size()) {
      if (isAliceTurn) {
        as += even[j];
      }
      j++;
      isAliceTurn = !isAliceTurn;
    }

    if (as == bs) {
      cout << "Tie\n";
    } else if (as > bs) {
      cout << "Alice\n";
    } else {
      cout << "Bob\n";
    }
  }
}