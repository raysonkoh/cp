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

void printVect(vector<vector<bool>> &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j];
    }
    cout << '\n';
  }
}

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m;
  while (cin >> m) {
    if (m == 0) break;
    int w, h;
    vector<int> wds;
    vector<int> hts;
    int numRows = 0;
    while (cin >> w >> h) {
      if (w == -1 && h == -1) break;
      if (numRows == 0) {
        wds.push_back(w);
        hts.push_back(h);
        numRows++;
        continue;
      }

      if (wds.back() + w <= m) {
        wds.back() += w;
        hts[hts.size() - 1] = max(hts.back(), h);
        continue;
      }

      wds.push_back(w);
      hts.push_back(h);
      numRows++;
    }
    int ww = *max_element(wds.begin(), wds.end());
    int hh = 0;
    for (auto x : hts)
      hh += x;
    cout << ww << " x " << hh << '\n';
  }
}
