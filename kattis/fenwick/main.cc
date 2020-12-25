#include <iostream>
#include <vector>

#define LSOne(S) ((S) & -(S))

using namespace std;

long long BIT[5000001];

void update(int x, int n, long long delta) {
  for (; x < n + 1; x += LSOne(x)) {
    BIT[x] += delta;
  }
}

long long prefixSum(int x) {
  long long res = 0;
  for (; x; x -= LSOne(x)) {
    res += BIT[x];
  }
  return res;
}
/*
class BIT {
public:
  vector<long long> v;
  BIT(int n) { v.assign(n + 1, 0); }
  void update(int x, long long delta) {
    for (; x < v.size(); x += LSOne(x)) {
      v[x] += delta;
    }
  }
  long long prefixSum(int x) {
    long long res = 0;
    for (; x; x -= LSOne(x)) {
      res += v[x];
    }
    return res;
  }
};
*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  // scanf("%d %d", &n, &q);
  cin >> n >> q;
  // BIT myBIT(n);
  for (int i = 0; i < q; i++) {
    char cmd;
    int x;
    // scanf(" %c %d", &cmd, &x);
    cin >> cmd >> x;
    // cout << "cmd: " << cmd << " x: " << x << endl;
    if (cmd == '+') {
      long long delta;
      // scanf("%lld", &delta);
      cin >> delta;
      // cout << "delta: " << delta << endl;
      x++;
      update(x, n, delta);
    } else {
      // '?'
      if (x == 0) {
        cout << "0\n";
        // printf("0\n");
      } else {
        cout << prefixSum(x) << "\n";
        // printf("%lld\n", prefixSum(x));
      }
    }
  }
}