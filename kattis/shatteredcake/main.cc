#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int w, n;
  cin >> w >> n;
  long long area = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    area += a * b;
  }
  long long res = area / w;
  cout << res << endl;
}