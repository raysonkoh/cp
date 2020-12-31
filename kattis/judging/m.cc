#include <iostream>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<string, int> dom;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (dom.find(s) == dom.end()) {
      dom[s] = 0;
    }
    dom[s]++;
  }

  map<string, int> kat;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (kat.find(s) == kat.end()) {
      kat[s] = 0;
    }
    kat[s]++;
  }

  int res = 0;
  for (auto it : dom) {
    if (kat.find(it.first) != kat.end()) {
      res += min(kat[it.first], it.second);
    }
  }
  cout << res << endl;
}