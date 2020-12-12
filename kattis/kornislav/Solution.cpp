#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  v.push_back(d);
  sort(v.begin(), v.end());
  cout << v[0] * v[2] << endl;
  return 0;
}