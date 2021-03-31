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
  int t;
  cin >> t;
  while (t--) {
    int n1;
    cin >> n1;
    vector<int> v1(n1 + 1);
    for (int i = 0; i < v1.size(); i++) cin >> v1[i];
    int n2;
    cin >> n2;
    vector<int> v2(n2 + 1);
    for (int i = 0; i < v2.size(); i++) cin >> v2[i];

    vector<int> res(n1 + n2 + 1, 0);
    for (int i = 0; i < v1.size(); i++) {
      for (int j = 0; j < v2.size(); j++) {
        res[i + j] += v1[i] * v2[j];
      }
    }

    int deg = res.size() - 1;
    while (res[deg] == 0) {
      deg--;
    }
    cout << deg << '\n';
    for (int i = 0; i <= deg; i++) {
      cout << res[i] << " ";
    }
    cout << '\n';
  }
}
