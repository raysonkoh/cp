#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int r, c;
  cin >> r >> c;
  vector<vector<char>> v(r, vector<char>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> v[i][j];
    }
  }

  int currR = 0;
  int currC = 0;
  vector<vector<bool>> visited(r, vector<bool>(c, false));
  visited[currR][currC] = true;

  int moves = 0;
  while (true) {
    char ch = v[currR][currC];
    int nextR = currR;
    int nextC = currC;
    switch (ch) {
    case 'N':
      nextR--;
      break;
    case 'S':
      nextR++;
      break;
    case 'E':
      nextC++;
      break;
    case 'W':
      nextC--;
      break;
    case 'T': {
      cout << moves << '\n';
      return 0;
    }
    }

    if (nextR < 0 || nextR >= r || nextC < 0 || nextC >= c) {
      cout << "Out\n";
      return 0;
    } else if (visited[nextR][nextC]) {
      cout << "Lost\n";
      return 0;
    } else {
      visited[nextR][nextC] = true;
      currR = nextR;
      currC = nextC;
      moves++;
    }
  }
}