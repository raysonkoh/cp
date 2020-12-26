#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m, n;
  cin >> m >> n;
  vector<vector<bool>> translate(26, vector<bool>(26, false));
  for (int i = 0; i < m; i++) {
    char a, b;
    cin >> a >> b;
    int aAscii = ((int)a) - 97;
    int bAscii = ((int)b) - 97;
    translate[aAscii][bAscii] = true;
  }
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    if (a.length() != b.length()) {
      cout << "no"
           << "\n";
      continue;
    }
    bool canTranslate = true;
    for (int i = 0; i < a.length(); i++) {
      int aAscii = ((int)a.at(i)) - 97;
      int bAscii = ((int)b.at(i)) - 97;
      vector<bool> seen(26, false);
      queue<int> q;
      q.push(aAscii);
      seen[aAscii] = true;
      bool canTranslateLetter = false;
      while (q.size() > 0) {
        int next = q.front();
        q.pop();
        if (next == bAscii) {
          canTranslateLetter = true;
          break;
        }
        for (int j = 0; j < 26; j++) {
          if (translate[next][j] && !seen[j]) {
            q.push(j);
            seen[j] = true;
          }
        }
        // cout << (char)(aAscii + 97) << " to " << (char)(translate[aAscii] +
        // 97)
        //     << endl;
      }
      if (!canTranslateLetter) {
        canTranslate = false;
        break;
      }
    }
    cout << (canTranslate ? "yes" : "no") << "\n";
  }
}