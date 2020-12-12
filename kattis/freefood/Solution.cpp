#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int si, ti;
    cin >> si >> ti;
    for (int j = si; j <= ti; j++) {
      s.insert(j);
    }
  }
  cout << s.size() << endl;
  return 0;
}
