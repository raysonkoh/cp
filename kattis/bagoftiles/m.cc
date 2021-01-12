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

class NChooseK {
public:
  vector<vector<long long>> binomTable;
  NChooseK(int nMax, int kMax) {
    binomTable.assign(nMax + 1, vector<long long>(kMax + 1));
    initBinomTable();
  }
  void initBinomTable() {
    for (long long i = 0; i < binomTable.size(); i++) {
      for (long long j = 0; j < binomTable[i].size(); j++) {
        if (j == 0) {
          binomTable[i][j] = 1;
        } else if (i == 0) {
          binomTable[i][j] = 0;
        } else if (j == 1) {
          binomTable[i][j] = i;
        } else {
          binomTable[i][j] = binomTable[i - 1][j] + binomTable[i - 1][j - 1];
        }
      }
    }
  }
  long long query(int n, int k) { return binomTable[n][k]; }
};

void countSubsetSum(vector<int> &v, int offset, vector<vector<long long>> &dp) {
  int exp = dp.size() - 1;
  int t = dp[0].size();
  int maxSize = 1 << exp;

  for (int i = 0; i < maxSize; i++) {
    int tol = 0;
    int len = 0;
    for (int j = 0; j < exp; j++) {
      // cout << "i: " << i << " j: " << j << " offset: " << offset << endl;
      if (i & (1 << j)) {
        tol += v[j + offset];
        len++;
      }
    }

    if (tol < t)
      dp[len][tol]++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int g;
  cin >> g;
  NChooseK nCk(30, 30);
  for (int game = 1; game <= g; game++) {
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
      cin >> v[i];
    }
    int n, t;
    cin >> n >> t;

    int leftSize = m / 2;
    int rightSize = m - leftSize;

    vector<vector<long long>> left(leftSize + 1, vector<long long>(t + 1, 0));   // left[i][j] : count of i numbers summing to j in A[1...m/2]
    vector<vector<long long>> right(rightSize + 1, vector<long long>(t + 1, 0)); // right[i][j] : count of i numbers summing to j in A[m/2 + 1...m - 1]

    countSubsetSum(v, 0, left); // O(2^(m/2) * m/2)
    countSubsetSum(v, leftSize, right);

    long long res = 0;
    for (int i = 0; i < leftSize + 1; i++) {
      for (int j = 0; j < t + 1; j++) {
        if (left[i][j] > 0 && n - i >= 0 && n - i < rightSize + 1 && t - j >= 0 && t - j < t + 1) {
          // cout << "left " << i << " " << j << " val: " << left[i][j] << endl;
          // cout << "right " << n - i << " " << t - j << " val: " << right[n - i][t - j] << endl;
          res += left[i][j] * right[n - i][t - j];
        }
      }
    }

    cout << "Game " << game << " -- " << res << " : " << nCk.query(m, n) - res << '\n';
  }
}