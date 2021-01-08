#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<double> v(10002);
  vector<double> s(10002);
  v[0] = 1.0;
  s[0] = 1.0;
  for (double i = 1; i < v.size(); i++) {
    v[i] = v[i - 1] * (1.0 / i);
    s[i] = s[i - 1] + v[i];
  }

  int n;
  cin >> n;

  cout << fixed << setprecision(13) << s[n] << '\n';
}