#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<string> s;
  for (int i = 0; i < n; i++) {
    string uni, team;
    cin >> uni >> team;
    if (s.find(uni) == s.end() && s.size() < 12) {
      cout << uni << " " << team << endl;
      s.insert(uni);
    }
  }
}