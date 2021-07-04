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

  printf("%d\n", n);
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    v[i] = i + 1;

  shuffle(v.begin(), v.end());

  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);

  printf("\n");

  return 0;
}
