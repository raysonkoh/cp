#include <algorithm>
#include <climits>
#include <cmath>
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
#define LSOne(S) ((S) & -(S))

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  while (cin >> n >> m) {
    vector<set<int>> sets(n + 1, set<int>());
    vector<int> compId(n + 1);
    vector<long long> sum(n + 1);
    vector<int> size(n + 1, 1);
    for (int i = 0; i < n + 1; i++) {
      sets[i].insert(i);
      compId[i] = i;
      sum[i] = i;
    }

    while (m--) {
      int cmd;
      cin >> cmd;
      switch (cmd) {
      case 1: {
        int p, q;
        cin >> p >> q;
        int pid = compId[p];
        int qid = compId[q];
        if (pid == qid) {
          break;
        }

        if (size[pid] > size[qid]) {
          swap(pid, qid);
        }

        for (auto x : sets[pid]) {
          sets[qid].insert(x);
          compId[x] = qid;
        }
        sets[pid].clear();

        sum[qid] += sum[pid];
        sum[pid] = 0;
        size[qid] += size[pid];
        size[pid] = 0;

        break;
      }
      case 2: {
        int p, q;
        cin >> p >> q;
        int pid = compId[p];
        int qid = compId[q];
        if (pid == qid) {
          break;
        }

        sets[pid].erase(p);
        sum[pid] -= p;
        size[pid]--;

        sets[qid].insert(p);
        sum[qid] += p;
        size[qid]++;

        compId[p] = qid;
        break;
      }
      case 3: {
        int p;
        cin >> p;
        int pid = compId[p];
        cout << size[pid] << " " << sum[pid] << '\n';
        break;
      }
      }
    }
  }
}
