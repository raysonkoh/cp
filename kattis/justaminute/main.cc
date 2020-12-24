#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  double tolm = 0;
  double tols = 0;
  for (int i = 0; i < n; i++) {
    int m, s;
    cin >> m >> s;
    tolm += m;
    tols += s;
  }
  double res = tols / (tolm * 60.0);
  if (res <= 1) {
    cout << "measurement error" << endl;
  } else {
    cout << fixed << setprecision(8) << tols / (tolm * 60.0) << endl;
  }
}