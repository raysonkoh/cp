#include <iostream>
#include <vector>

using namespace std;

void pr(int x, vector<int> &v) {
  if (v[x] == 0)
    cout << "none\n";
  else if (v[x] == 1)
    cout << "one\n";
  else
    cout << "both\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<int> v(1000, 0);
  int i = 1;
  while (i < v.size()) {
    int tmp = 0;
    while (tmp < a) {
      if (i < v.size()) {
        v[i]++;
        i++;
        tmp++;
      } else {
        break;
      }
    }
    i += b;
  }

  i = 1;
  while (i < v.size()) {
    int tmp = 0;
    while (tmp < c) {
      if (i < v.size()) {
        v[i]++;
        i++;
        tmp++;
      } else {
        break;
      }
    }
    i += d;
  }

  int p, m, g;
  cin >> p >> m >> g;
  pr(p, v);
  pr(m, v);
  pr(g, v);
}