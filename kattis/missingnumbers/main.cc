#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  set<int> seen;
  int last;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i == n - 1) {
      last = x;
    }
    seen.insert(x);
  }

  bool isGoodJob = true;
  for (int i = 1; i <= last; i++) {
    if (seen.find(i) == seen.end()) {
      isGoodJob = false;
      cout << i << endl;
    }
  }
  if (isGoodJob) {
    cout << "good job" << endl;
  }
}