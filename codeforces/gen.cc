#include "testlib.h"

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);

  int n = opt<int>(1);

  cout << n << endl;
  for (int i = 0; i < n; i++) {

    // cout << rnd.next(1, 10) << endl;
    // cout << rnd.next("[a-z]{1,3}") << endl;
  }

  // shuffle(v.begin(), v.end());

  return 0;
}
