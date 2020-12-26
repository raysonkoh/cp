#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  vector<string> v;
  long long maxLen = 0;
  while (getline(cin, s)) {
    v.push_back(s);
    maxLen = max(maxLen, (long long)s.length());
  }
  long long res = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    res += (maxLen - v[i].length()) * (maxLen - v[i].length());
  }
  cout << res << endl;
}