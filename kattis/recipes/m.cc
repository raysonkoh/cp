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
  int caseNum = 1;
  while (t--) {
    cout << "Recipe # " << caseNum << '\n';
    caseNum++;
    int r;
    double p, d;
    cin >> r >> p >> d;
    double scale = d / p;
    vector<tuple<string, double, double>> v(r);
    int mainIndx;
    for (int i = 0; i < r; i++) {
      string s;
      double wt, per;
      cin >> s >> wt >> per;
      v[i] = {s, wt, per};
      if (per == 100) {
        mainIndx = i;
      }
    }

    get<1>(v[mainIndx]) *= scale;
    for (int i = 0; i < r; i++) {
      if (i != mainIndx) {
        get<1>(v[i]) = get<1>(v[mainIndx]) * get<2>(v[i]) / 100.0;
      }

      cout << fixed << setprecision(2) << get<0>(v[i]) << " " << get<1>(v[i]) << '\n';
    }
    cout << "----------------------------------------\n";
  }
}
