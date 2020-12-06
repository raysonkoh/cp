#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, int> m;
  int res = 0;
  for (int i = 0; i < 10; i++) {
    int tmp;
    cin >> tmp;
    int remain = tmp % 42;
    if (m.find(remain) == m.end()) {
      res++;
      m[remain] = 1;
    }
  }
  cout << res << endl;
  return 0;
}