#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int k;
  cin >> k;
  while (k--) {

    int n;
    cin >> n;
    vector<int> indxToNum(n);
    vector<int> numToIndx(n + 1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      indxToNum[i] = x;
      numToIndx[x] = i;
    }

    int end = n;
    int res = 0;
    int prevIndx = numToIndx[1];
    for (int i = 2; i <= n; i++) {
      int indx = numToIndx[i];
      if (indx > prevIndx) {
        prevIndx = indx;
      } else {
        // move i to top of stack
        numToIndx[i] = end;
        prevIndx = end;
        end++;
        res++;
      }
    }

    cout << res << '\n';
  }
}
