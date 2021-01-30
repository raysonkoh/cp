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
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

double calcDistSq(pair<double, double> a, pair<double, double> b) {
  return pow(abs(a.first - b.first), 2) + pow(abs(a.second - b.second), 2);
}

pair<pair<double, double>, pair<double, double>> closestPair(vector<pair<double, double>> &vX, vector<pair<double, double>> &vY) {
  int midPt = vX.size() / 2;
  if (vX.size() <= 1) {
    return {{1e18, 1e18}, {2e18, 2e18}};
  }
  vector<pair<double, double>> leftX, rightX, leftY, rightY;
  for (int i = 0; i < vX.size(); i++) {
    if (i < midPt) {
      leftX.push_back(vX[i]);
    } else {
      rightX.push_back(vX[i]);
    }
  }
  for (auto [a, b] : vY) {
    if (a <= leftX.back().first) {
      leftY.push_back({a, b});
    } else {
      rightY.push_back({a, b});
    }
  }

  // recurse
  auto [l1, l2] = closestPair(leftX, leftY);
  auto [r1, r2] = closestPair(rightX, rightY);
  double l = calcDistSq(l1, l2);
  double r = calcDistSq(r1, r2);
  double minDist;
  pair<double, double> best1, best2;
  if (l < r) {
    minDist = l;
    best1 = l1;
    best2 = l2;
  } else {
    minDist = r;
    best1 = r1;
    best2 = r2;
  }

  vector<pair<double, double>> stripe;  // sorted by y
  for (int i = 0; i < vY.size(); i++) {
    if (abs(vY[i].first - leftX.back().first) < minDist) {
      stripe.push_back(vY[i]);
    }
  }

  for (int i = 0; i < stripe.size(); i++) {
    // O(1) loop because <=16 elements in 2d x 2d square
    for (int j = i + 1; j < stripe.size() && stripe[j].second - stripe[i].second < minDist; j++) {
      double tmp = calcDistSq(stripe[i], stripe[j]);
      if (tmp < minDist) {
        minDist = tmp;
        best1 = stripe[i];
        best2 = stripe[j];
      }
    }
  }
  return {best1, best2};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<pair<double, double>> vX(n);
    vector<pair<double, double>> vY(n);
    for (int i = 0; i < n; i++) {
      double x, y;
      cin >> x >> y;
      vX[i] = {x, y};
      vY[i] = {x, y};
    }
    sort(vX.begin(), vX.end());
    sort(vY.begin(), vY.end(), [](pair<double, double> a, pair<double, double> b) {
      return a.second < b.second;
    });
    auto [a, b] = closestPair(vX, vY);
    cout << fixed << setprecision(2) << a.first << " " << a.second << " " << b.first << " " << b.second << "\n";
  }
}
