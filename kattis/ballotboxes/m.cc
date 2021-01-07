#include <cmath>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, b;
  while (cin >> n >> b) {
    if (n == -1 && b == -1)
      break;

    priority_queue<tuple<double, double, double>> pq; // (divded num, actual num, divisor)
    for (int i = 0; i < n; i++) {
      double x;
      cin >> x;
      b--;
      pq.push({x, x, 1});
    }

    while (b) {
      auto [dividedNum, actualNum, divisor] = pq.top();
      pq.pop();
      pq.push({ceil(actualNum / (divisor + 1.0)), actualNum, divisor + 1.0});
      b--;
    }

    cout << get<0>(pq.top()) << '\n';
  }
}