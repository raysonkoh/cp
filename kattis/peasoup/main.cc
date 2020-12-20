#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    string name;
    getline(cin, name);
    getline(cin, name);
    set<string> s;
    string fd;
    for (int j = 0; j < k; j++) {
      getline(cin, fd);
      s.insert(fd);
    }
    if (s.find("pea soup") != s.end() && s.find("pancakes") != s.end()) {
      cout << name << endl;
      return 0;
    }
  }
  cout << "Anywhere is fine I guess" << endl;
}