#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    priority_queue<int> red;
    priority_queue<int> blue;
    for (int j = 0; j < s; j++) {
      string s;
      cin >> s;
      int l = stoi(s.substr(0, s.length() - 1));
      char c = s[s.length() - 1];
      if (c == 'R') {
        red.push(l);
      } else {
        blue.push(l);
      }
    }
    if (red.size() == 0 || blue.size() == 0) {
      cout << "Case #" << i + 1 << ": " << 0 << endl;
      continue;
    }
    int res = 0;
    int numConnect = 0;
    char initial = ' ';
    while (red.size() > 0 && blue.size() > 0) {
      if (initial == ' ') {
        if (red.top() > blue.top()) {
          // cout << "add red " << red.top() << endl;
          res += red.top();
          red.pop();
          initial = 'R';
          res += blue.top();
          blue.pop();
        } else {
          // cout << "add blue " << blue.top() << endl;
          res += blue.top();
          blue.pop();
          initial = 'B';
          res += red.top();
          red.pop();
        }
      } else if (initial == 'R') {
        // cout << "add blue " << blue.top() << endl;
        res += red.top();
        red.pop();
        res += blue.top();
        blue.pop();
      } else {
        // cout << "add red " << red.top() << endl;
        res += blue.top();
        blue.pop();
        res += red.top();
        red.pop();
      }

      numConnect += 2;
    }

    cout << "Case #" << i + 1 << ": " << res - numConnect << endl;
  }
}