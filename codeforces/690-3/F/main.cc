#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> start(n);
    vector<long long> end(n);
    vector<pair<long long, long long>> segments(n);
    for (int i = 0; i < n; i++) {
      long long st, ed;
      cin >> st >> ed;
      start[i] = st;
      end[i] = ed;
      segments[i] = make_pair(st, ed);
    }
    int bestNumIntersect = 0;
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    for (int i = 0; i < n; i++) {
      pair<long long, long long> p = segments[i];
      int numStartAfterIEnd =
          upper_bound(start.begin(), start.end(), p.second) - start.begin();
      numStartAfterIEnd = n - numStartAfterIEnd;
      int numEndBeforeIStart =
          lower_bound(end.begin(), end.end(), p.first) - end.begin();
      int numIntersect = n - numStartAfterIEnd - numEndBeforeIStart;
      // cout << "(" << p.first << "," << p.second
      //     << ") after end: " << numStartAfterIEnd
      //     << " before start: " << numEndBeforeIStart << endl;
      bestNumIntersect = max(bestNumIntersect, numIntersect);
    }
    cout << n - bestNumIntersect << "\n";
  }
}