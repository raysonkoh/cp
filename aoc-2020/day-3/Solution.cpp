#include <iostream>
#include <string>
#include <vector>

using namespace std;

long findNumTree(vector<string> v, int n, int m, int xoffset, int yoffset) {
  int xpos = xoffset % m;
  long res = 0;
  for (int r = yoffset; r < n; r += yoffset) {
    char c = v[r].at(xpos);
    if (c == '#') {
      res++;
    }
    xpos = (xpos + xoffset) % m;
  }
  return res;
}

int main() {
  int n = 323;
  int m = -1;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    if (m == -1) {
      m = tmp.length();
    }
    v.push_back(tmp);
  }

  long a = findNumTree(v, n, m, 1, 1);
  long b = findNumTree(v, n, m, 3, 1);
  long c = findNumTree(v, n, m, 5, 1);
  long d = findNumTree(v, n, m, 7, 1);
  long e = findNumTree(v, n, m, 1, 2);
  long res = a * b * c * d * e;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << e << endl;
  cout << res << endl;
  return 0;
}