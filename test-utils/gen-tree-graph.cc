#include "testlib.h"

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);

  int n = opt<int>(1);
  int t = opt<int>(2);

  vector<int> p(n);
  forn(i, n) if (i > 0)
      p[i] = rnd.wnext(i, t);

  printf("%d\n", n);
  vector<int> perm(n);
  forn(i, n)
      perm[i] = i;
  shuffle(perm.begin() + 1, perm.end());
  vector<pair<int, int>> edges;

  for (int i = 1; i < n; i++)
    if (rnd.next(2))
      edges.push_back(make_pair(perm[i], perm[p[i]]));
    else
      edges.push_back(make_pair(perm[p[i]], perm[i]));

  shuffle(edges.begin(), edges.end());

  for (int i = 0; i + 1 < n; i++)
    printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);

  return 0;
}
