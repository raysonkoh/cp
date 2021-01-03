#include <iostream>
#include <list>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;

  string s;
  getline(cin, s);

  while (t--) {
    getline(cin, s);
    list<char> l;
    auto currIt = l.begin();
    for (char c : s) {
      if (c == '<') {
        if (currIt != l.begin()) {
          currIt--;
          currIt = l.erase(currIt);
        }
      } else if (c == '[') {
        currIt = l.begin();
      } else if (c == ']') {
        currIt = l.end();
      } else {
        currIt = l.insert(currIt, c);
        currIt++;
      }
    }

    for (char c : l) {
      cout << c;
    }
    cout << "\n";
  }
}