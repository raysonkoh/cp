#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// calculates the distance squared
double calcDistSq(pair<double, double> a, pair<double, double> b) {
  return pow(abs(a.first - b.first), 2) + pow(abs(a.second - b.second), 2);
}

// calculates distance of closest points in O(nlogn) using divide and conquer
// and Lemma that states that num of points within 2d x 2d box in the stripe is O(1)
// due to the fact that points each point has a circle of radius d in which other
// points should not be in because otherwise d would not be the minimum distance (contradiction)
double closestPair(vector<pair<double, double>> &vX, vector<pair<double, double>> &vY) {
  int midPt = vX.size() / 2;
  if (vX.size() <= 1) {
    return 2e18;
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
  double l = closestPair(leftX, leftY);
  double r = closestPair(rightX, rightY);
  double minDist;
  if (l < r) {
    minDist = l;
  } else {
    minDist = r;
  }

  vector<pair<double, double>> stripe; // sorted by y
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
      }
    }
  }
  return minDist;
}
