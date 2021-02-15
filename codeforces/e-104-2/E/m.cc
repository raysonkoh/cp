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
  long long n1, n2, n3, n4;
  cin >> n1 >> n2 >> n3 >> n4;
  vector<long long> v1(n1);
  for (int i = 0; i < n1; i++)
    cin >> v1[i];
  vector<long long> v2(n2);
  for (int i = 0; i < n2; i++)
    cin >> v2[i];
  vector<long long> v3(n3);
  for (int i = 0; i < n3; i++)
    cin >> v3[i];
  vector<long long> v4(n4);
  for (int i = 0; i < n4; i++)
    cin >> v4[i];

  long long m1;
  cin >> m1;
  vector<vector<int>> cannot1(n1, vector<int>());
  for (int i = 0; i < m1; i++) {
    int x, y;
    cin >> x >> y;
    cannot1[x].push_back(y);
  }

  long long m2;
  cin >> m2;
  vector<vector<int>> cannot2(n2, vector<int>());
  for (int i = 0; i < m2; i++) {
    int x, y;
    cin >> x >> y;
    cannot2[x].push_back(y);
  }

  long long m3;
  cin >> m3;
  vector<vector<int>> cannot3(n3, vector<int>());
  for (int i = 0; i < m3; i++) {
    int x, y;
    cin >> x >> y;
    cannot3[x].push_back(y);
  }
}
