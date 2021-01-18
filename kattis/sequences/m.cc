#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11
#define LSOne(S) ((S) & -(S))

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  char c;
  vector<int> prefixOnes{0};
  vector<int> prefixKs{0};
  vector<int> v;
  int k = 0;
  while (cin >> c) {
    if (c == '1') {
      prefixOnes.push_back(prefixOnes.at(prefixOnes.size() - 1) + 1);
      prefixKs.push_back(prefixKs.at(prefixKs.size() - 1));
      v.push_back(1);
    } else if (c == '?') {
      prefixOnes.push_back(prefixOnes.at(prefixOnes.size() - 1));
      prefixKs.push_back(prefixKs.at(prefixKs.size() - 1) + 1);
      v.push_back(-1);
      k++;
    } else {
      prefixOnes.push_back(prefixOnes.at(prefixOnes.size() - 1));
      prefixKs.push_back(prefixKs.at(prefixKs.size() - 1));
      v.push_back(0);
    }
  }

  vector<long long> expTable(k + 1);
  expTable[0] = 1;
  for (int i = 1; i < expTable.size(); i++) {
    expTable[i] = (2 * expTable[i - 1]) % ((long long)P);
  }

  long long res = 0;
  for (int i = prefixOnes.size() - 1; i >= 2; i--) {
    if (v[i - 1] == 1) {
      continue;
    } else if (v[i - 1] == -1) {
      // set as 0
      long long numKs = prefixKs[i] - 1;
      res = (res + expTable[k - 1] * prefixOnes[i] + expTable[k - 2] * numKs) % ((long long)P);
    } else {
      int numKs = prefixKs[i];
      res = (res + expTable[k] * prefixOnes[i] + expTable[k - 1] * numKs) % ((long long)P);
    }
  }

  res = (res + (long long)P) % ((long long)P);

  cout << res << '\n';
}
