#include <iostream>
#include <stack>

using namespace std;

int nextThrowIndx(int i, int n, int offset) {
  int res = (i + offset) % n;
  if (res < 0)
    res += n;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int currPos = 0;
  stack<int> stk;
  for (int i = 0; i < k; i++) {
    string s;
    int x;
    cin >> s;
    if (s == "undo") {
      cin >> x;
      while (x--) {
        currPos = nextThrowIndx(currPos, n, stk.top());
        stk.pop();
      }
    } else {
      x = stoi(s);
      currPos = nextThrowIndx(currPos, n, x);
      stk.push(-x);
    }
  }
  cout << currPos << endl;
}
