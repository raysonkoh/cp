#include <cmath>
#include <iostream>

using namespace std;

pair<int, int> case1(int s, int d) {
  int b = (s - d) / 2;
  int a = s - b;
  return {a, b};
}

pair<int, int> case2(int s, int d) {
  int b = (s + d) / 2;
  int a = s - b;
  return {a, b};
}

bool verify(int a, int b, int s, int d) { return a >= 0 && b >= 0 && (a + b == s) && (abs(a - b) == d); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int s, d;
    cin >> s >> d;

    auto [a, b] = case1(s, d);
    if (verify(a, b, s, d)) {
      if (b > a)
        swap(a, b);
      cout << a << " " << b << endl;
    } else {
      auto [a, b] = case2(s, d);
      if (verify(a, b, s, d)) {
        if (b > a)
          swap(a, b);
        cout << a << " " << b << endl;
      } else {
        cout << "impossible\n";
      }
    }
  }
}