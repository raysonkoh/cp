#include <iostream>
#include <vector>

using namespace std;

int main() {
  long n, m;
  while (cin >> n >> m) {
    long res = 0;
    if (n == 0 && m == 0) {
      break;
    }

    /*
    vector<long long> v(1000000);
    for (int i = 0; i < 1000000; i++) {
      long long tmp;
      if (i < n) {
        cin >> tmp;
      }
      v[i] = i + 1;
    }
    */

    vector<long long> v(n);
    for (long i = 0; i < n; i++) {
      long long tmp;
      cin >> tmp;
      v[i] = tmp;
    }

    long lo = 0;
    long hi = n - 1;
    for (long i = 0; i < m; i++) {
      // cout << "lo: " << lo << " hi: " << hi << endl;
      long long tmp;
      cin >> tmp;
      // binsearch tmp in v
      bool isFound = false;
      while (lo < hi) {
        long mid = lo + ((hi - lo) / 2);
        // cout << "lo: " << lo << " hi: " << hi << " mid: " << mid
        //     << " ele: " << v[mid] << endl;
        if (v[mid] == tmp) {
          res++;
          lo = mid + 1;
          hi = n - 1;
          isFound = true;
          break;
        } else if (v[mid] < tmp) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }

      if (!isFound) {
        if (v[lo] == tmp) {
          res++;
          lo++;
        }
        hi = n - 1;
      }
    }
    cout << res << endl;
  }
  return 0;
}