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

class LIS {
public:
  int n;
  vector<int> v;
  vector<int> par;            // stores parent pointers
  vector<int> incrSubSeq;     // stores Min Last Ele for increasing subseq of length i
  vector<int> incrSubSeqIndx; // stores Min Last Ele Indx for increasing subseq of length i
  LIS(vector<int> &arr) : n(arr.size()), v(arr) { par.assign(n, 0); }
  void run() {
    incrSubSeq.push_back(v[0]);
    incrSubSeqIndx.push_back(0);
    par[0] = -1;
    int i = 1;
    while (i < n) {
      if (v[i] > incrSubSeq[incrSubSeq.size() - 1]) {
        par[i] = incrSubSeqIndx[incrSubSeq.size() - 1];
        incrSubSeq.push_back(v[i]);
        incrSubSeqIndx.push_back(i);
      } else {
        int replaceIndx = lower_bound(incrSubSeq.begin(), incrSubSeq.end(), v[i]) - incrSubSeq.begin();
        incrSubSeq[replaceIndx] = v[i];
        incrSubSeqIndx[replaceIndx] = i;

        if (replaceIndx - 1 >= 0) {
          par[i] = incrSubSeqIndx[replaceIndx - 1];
        } else {
          par[i] = -1;
        }
      }
      i++;
    }
  }

  vector<int> getLongestSeq() {
    int maxLen = incrSubSeq.size();
    vector<int> longestSubSeq(maxLen);
    int currIndx = incrSubSeqIndx[maxLen - 1];
    int i = maxLen - 1;
    while (i + 1) {
      longestSubSeq[i] = currIndx;
      currIndx = par[currIndx];
      i--;
    }
    return longestSubSeq;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    LIS lis(v);
    lis.run();
    vector<int> res = lis.getLongestSeq();
    cout << res.size();
    for (auto x : res)
      cout << " " << v[x];
    cout << '\n';
  }
}
