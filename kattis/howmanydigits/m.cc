#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<double> v(1000001);

void init() {
  for (int i = 1; i < v.size(); i++) {
    if (i == 1) {
      v[i] = log10(i);
    } else {
      v[i] = v[i - 1] + log10(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  int x;
  while (cin >> x) {
    cout << ((int)v[x]) + 1 << '\n';
  }
}