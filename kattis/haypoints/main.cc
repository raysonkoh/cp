#include <iostream>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m, n;
  cin >> m >> n;
  map<string, int> dict;
  for (int i = 0; i < m; i++) {
    string a;
    int d;
    cin >> a >> d;
    dict[a] = d;
  }
  string s;
  int jobNum = 0;
  long long res = 0;
  while (jobNum < n) {
    cin >> s;
    if (s == ".") {
      cout << res << "\n";
      res = 0;
      jobNum++;
      continue;
    }
    if (dict.find(s) != dict.end()) {
      res += dict[s];
    }
  }
}