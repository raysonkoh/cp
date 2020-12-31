#include <iostream>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  map<string, int> count;
  int tolCt = 0;
  while (getline(cin, s)) {
    if (s == "***") {
      break;
    }
    if (count.find(s) == count.end()) {
      count[s] = 0;
    }
    count[s]++;
    tolCt++;
  }

  int maxCt = 0;
  string best;
  bool hasDuplicate = false;
  for (auto it : count) {
    if (it.second > tolCt / 2) {
      cout << it.first << endl;
      return 0;
    }

    if (it.second > maxCt) {
      maxCt = it.second;
      best = it.first;
      hasDuplicate = false;
    } else if (it.second == maxCt) {
      hasDuplicate = true;
    }
  }

  if (!hasDuplicate) {
    cout << best << endl;
    return 0;
  }

  cout << "Runoff!" << endl;
}
