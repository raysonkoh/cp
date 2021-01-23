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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i < n; i++) {
    int numer = v[0];
    int denom = v[i];
    int minNum = min(numer, denom);
    for (int j = 2; j <= minNum; j++) {
      while (numer % j == 0 && denom % j == 0) {
        numer /= j;
        denom /= j;
      }
    }
    cout << numer << "/" << denom << '\n';
  }
}