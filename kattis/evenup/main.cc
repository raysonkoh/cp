#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  stack<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.push(x);
  }
  int res = n;
  stack<int> other;
  while (s.size() > 1) {
    int first = s.top();
    s.pop();
    int second = s.top();
    if ((first + second) % 2 == 0) {
      res -= 2;
      s.pop();
      if (other.size() > 0) {
        s.push(other.top());
        other.pop();
      }
    } else {
      other.push(first);
    }
  }
  cout << res << endl;
}