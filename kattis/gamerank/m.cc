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

int getNumStars(int rank) {
  if (rank >= 21)
    return 2;
  else if (rank >= 16)
    return 3;
  else if (rank >= 11)
    return 4;
  else
    return 5;
}

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int rank = 25;
  int stars = 0;
  int streak = 0;
  char ch;
  while (cin >> ch) {
    // cout << "BEFORE stars: " << stars << " rank: " << rank << " streak: " << streak << endl;
    if (ch == 'W') {
      // cout << "win" << endl;
      streak++;
      if (streak >= 3 && rank >= 6) {
        //cout << "STREAK" << endl;
        stars++;
      }
      if (stars >= getNumStars(rank)) {
        stars -= getNumStars(rank);
        rank--;
      }
      stars++;

      if (rank == 0)
        break;
    } else {
      // cout << "lose" << endl;
      // lose
      streak = 0;
      if (rank >= 21)
        continue;

      if (stars <= 0) {
        if (rank == 20) {
        } else {
          rank++;
          stars = getNumStars(rank) - 1;
        }
      } else {
        stars--;
      }
    }
    // cout << "AFTER stars: " << stars << " rank: " << rank << " streak: " << streak << endl;
  }
  cout << (rank == 0 ? "Legend" : to_string(rank)) << '\n';
}
