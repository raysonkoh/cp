#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int b, br, bs, a, as;
  cin >> b >> br >> bs >> a >> as;
  int offset = ((br - b) * bs) / as;
  cout << a + offset + 1 << endl;
}