#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  set<string> entered;
  for (int i = 0; i < n; i++) {
    string cmd, name;
    cin >> cmd >> name;
    if (cmd == "entry") {
      if (entered.find(name) == entered.end()) {
        entered.insert(name);
        cout << name << " entered" << endl;
      } else {
        cout << name << " entered (ANOMALY)" << endl;
      }
    } else {
      // exit
      if (entered.find(name) != entered.end()) {
        entered.erase(name);
        cout << name << " exited" << endl;
      } else {
        cout << name << " exited (ANOMALY)" << endl;
      }
    }
  }
}