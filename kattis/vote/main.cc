#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int tolvotes = 0;
    int bestvotes, res, count;
    for (int j = 0; j < n; j++) {
      int votes;
      cin >> votes;
      tolvotes += votes;
      if (j == 0) {
        bestvotes = votes;
        res = j + 1;
        count = 1;
      } else if (votes > bestvotes) {
        bestvotes = votes;
        res = j + 1;
        count = 1;
      } else if (votes == bestvotes) {
        count++;
      }
    }
    if (bestvotes > tolvotes / 2) {
      cout << "majority winner " << res << endl;
    } else if (count > 1) {
      cout << "no winner" << endl;
    } else {
      cout << "minority winner " << res << endl;
    }
  }
}