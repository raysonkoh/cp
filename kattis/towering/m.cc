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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<int> v(6);
  for (int i = 0; i < 6; i++)
    cin >> v[i];

  int h1, h2;
  cin >> h1 >> h2;
  sort(v.begin(), v.end());
  do {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 3; i++)
      v1.push_back(v[i]);
    for (int i = 3; i < 6; i++)
      v2.push_back(v[i]);

    if (v1[0] > v1[1] && v1[1] > v1[2] && v2[0] > v2[1] && v2[1] > v2[2]) {
      if (v1[0] + v1[1] + v1[2] == h1 && v2[0] + v2[1] + v2[2] == h2) {
        bool isFirst = true;
        for (int x : v) {
          if (isFirst)
            isFirst = false;
          else
            cout << " ";
          cout << x;
        }
        cout << '\n';
        break;
      }
    }
  } while (next_permutation(v.begin(), v.end()));
}
