#include <deque>
#include <iostream>

using namespace std;

int main() {
  char c;
  deque<char> d;
  while (cin >> c) {
    if (c == '<') {
      d.pop_back();
    } else {
      d.push_back(c);
    }
  }
  for (int i = 0; i < d.size(); i++) {
    cout << d[i];
  }
  cout << endl;
  return 0;
}