#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int c;
  cin >> c;
  for (int i = 0; i < c; i++) {
    int n;
    cin >> n;
    double res = 0;
    vector<double> v;
    for (int j = 0; j < n; j++) {
      double t;
      cin >> t;
      res += t;
      v.push_back(t);
    }
    double avg = res / ((double)n);
    double count = 0;
    for (int j = 0; j < v.size(); j++) {
      if (v[j] > avg) {
        count++;
      }
    }
    cout << fixed << setprecision(3) << count / n * 100.0 << "%" << endl;
  }
  return 0;
}