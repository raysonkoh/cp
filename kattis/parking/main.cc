#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> v(100, 0);
  for (int i = 0; i < 3; i++) {
    int start, end;
    cin >> start >> end;
    start--;
    end--;
    for (int j = start + 1; j <= end; j++) {
      v[j]++;
    }
  }
  int res = 0;
  for (int i = 1; i < 100; i++) {
    if (v[i] == 3) {
      res += 3 * c;
    } else if (v[i] == 2) {
      res += 2 * b;
    } else if (v[i] == 1) {
      res += a;
    }
  }
  cout << res << endl;
}