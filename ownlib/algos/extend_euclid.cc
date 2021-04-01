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

pair<long long, long long> extendEuclid(long long a, long long b) {  // returns {x,y}

  if (!b) return {1, 0};

  pair<long long, long long> p = extendEuclid(b, a % b);
  return {p.second, p.first - a / b * p.second};
}
