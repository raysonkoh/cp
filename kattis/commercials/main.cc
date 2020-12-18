#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, p;
  cin >> n >> p;
  int best = -1;
  int currbest = -1;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int prof = x - p;
    if (i == 0) {
      best = prof;
      currbest = prof;
    } else {
      currbest = max(prof, prof + currbest);
      best = max(best, currbest);
    }
  }
  cout << best << endl;
}
