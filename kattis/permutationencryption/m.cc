#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
      cin >> perm[i];

    string s;
    getline(cin, s);
    getline(cin, s);

    while (s.length() % n != 0) {
      s += ' ';
    }

    vector<char> tmp;
    for (int i = 1; i <= s.length(); i++) {
      tmp.push_back(s[i - 1]);
      if (i % n == 0) {
        for (int j = i - n + 1; j <= i; j++) {
          s[j - 1] = tmp[perm[j - (i - n + 1)] - 1];
        }
        tmp.clear();
      }
    }

    cout << "'" << s << "'" << '\n';
  }
}