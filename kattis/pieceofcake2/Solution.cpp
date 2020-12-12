#include <iostream>

using namespace std;

int main() {
  int n, h, v;
  cin >> n >> h >> v;
  int v1 = h * v;
  int v2 = h * (n - v);
  int v3 = (n - h) * v;
  int v4 = (n - h) * (n - v);
  cout << max(max(max(v1, v2), v3), v4) * 4 << endl;
  return 0;
}
