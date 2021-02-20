#include <algorithm>
#include <cassert>
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
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-9;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  set<long long> res;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      long long other = n / i;
      res.insert(i);
      res.insert(other);
    }
  }
  bool isFirst = true;
  for (auto x : res) {
    if (isFirst)
      isFirst = false;
    else
      cout << " ";
    cout << x - 1;
  }
  cout << '\n';
}
