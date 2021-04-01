#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-9;

using namespace std;

void pr(vector<bool> v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << '\n';
}

int convert(vector<bool> &v) {
  int curr = 0;
  vector<int> exp{128, 64, 32, 16, 8, 4, 2, 1};
  vector<bool> bits(8, false);
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i]) {
      curr = 1 - curr;
    }
    bits[i] = curr == 1;
  }

  curr = 0;
  for (int i = 0; i < bits.size(); i++) {
    if (bits[i]) curr += exp[i];
  }

  // pr(bits);

  return curr;
}

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vector<bool> bits(8, false);
    vector<int> exp{128, 64, 32, 16, 8, 4, 2, 1};
    for (int ii = 0; ii < 8; ii++) {
      bits[ii] = exp[ii] & x;
    }

    // pr(bits);

    int tmp = convert(bits);
    cout << tmp << ' ';
  }
  cout << '\n';
}
