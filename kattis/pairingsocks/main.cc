#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> v[i];
  }
  stack<int> s;
  stack<int> aux;
  for (int i = 2 * n - 1; i >= 0; i--) {
    s.push(v[i]);
  }
  int res = 0;
  while (s.size() > 0) {
    if (aux.size() == 0) {
      // cout << "init add to aux" << endl;
      aux.push(s.top());
      s.pop();
    } else if (s.top() == aux.top()) {
      // cout << "pop both" << endl;
      s.pop();
      aux.pop();
    } else {
      // cout << "s.top: " << s.top() << ", aux.top: " << aux.top() << endl;
      // cout << "add to aux" << endl;
      aux.push(s.top());
      s.pop();
    }
    res++;
  }
  cout << (aux.size() > 0 ? "impossible" : to_string(res)) << endl;
}