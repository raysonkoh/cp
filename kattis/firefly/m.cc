#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, h;
  cin >> n >> h;
  vector<int> fromBot(n / 2);
  vector<int> fromTop(n / 2);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      // fromBot
      cin >> fromBot[i / 2];
    } else {
      // fromTop
      cin >> fromTop[i / 2];
    }
  }
  sort(fromBot.begin(), fromBot.end());
  sort(fromTop.begin(), fromTop.end());

  int minObs = 1e9;
  int ct = 0;
  for (int i = 1; i <= h; i++) {
    int encounterFromBot = lower_bound(fromBot.begin(), fromBot.end(), i) - fromBot.begin();
    int encounterFromTop = lower_bound(fromTop.begin(), fromTop.end(), h - i + 1) - fromTop.begin();
    int tolObs = n - encounterFromBot - encounterFromTop;
    if (tolObs < minObs) {
      minObs = tolObs;
      ct = 1;
    } else if (tolObs == minObs) {
      ct++;
    }
  }
  cout << minObs << " " << ct << "\n";
}