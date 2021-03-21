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

bool firstOdd(int x) {
  int numEven = x / 2;
  int numOdd = x - numEven;
  return numOdd % 2 == 0;
}

bool firstEven(int x) {
  int numOdd = x / 2;
  return numOdd % 2 == 0;
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

  bool o = firstOdd(n);
  bool e = firstEven(n);
  if (o && e) {
    cout << "Even" << '\n';

  } else if ((!o) && (!e)) {
    cout << "Odd" << '\n';

  } else {
    cout << "Either" << '\n';
  }
}
