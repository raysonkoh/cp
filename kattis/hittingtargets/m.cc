#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

class Shape {
 public:
  virtual bool isInside(int x, int y) { return true; };
};
class Rect : public Shape {
 public:
  int x1, y1, x2, y2;
  Rect(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}
  bool isInside(int x, int y) override { return (x >= x1 && x <= x2) && (y >= y1 && y <= y2); }
};
class Circ : public Shape {
 public:
  int x, y, r;
  Circ(int a, int b, int c) : x(a), y(b), r(c) {}
  double dist(int x1, int y1) {
    double a = abs(x - x1);
    double b = abs(y - y1);
    return sqrt(a * a + b * b);
  }
  bool isInside(int x1, int y1) override {
    double d = dist(x1, y1);
    return d <= r;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m;
  cin >> m;
  vector<Shape *> v(m);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (s == "rectangle") {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      v[i] = new Rect(x1, y1, x2, y2);
    } else {
      // circle
      int x, y, r;
      cin >> x >> y >> r;
      v[i] = new Circ(x, y, r);
    }
  }
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    int res = 0;
    for (Shape *sh : v) {
      if (sh->isInside(x, y)) {
        res++;
      }
    }
    cout << res << '\n';
  }
}
