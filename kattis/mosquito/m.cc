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

// const long long P = 1e9 + 7;
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
  long long M, P, L, E, R, S, N;
  while (cin >> M >> P >> L >> E >> R >> S >> N) {
    // cout << "N:" << N << endl;
    for (int i = 0; i < N; i++) {
      // cout << "M: " << M << " P: " << P << " L: " << L << endl;
      long long numEggs = M * E;
      M = 0;
      M += P / S;
      P = 0;
      P += L / R;
      L = 0;
      L += numEggs;
    }
    cout << M << '\n';
  }
}
