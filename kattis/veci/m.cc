#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string x;
  cin >> x;
  int val = stoi(x);
  int res = 1e9;
  sort(x.begin(), x.end());
  do {
    if (x[0] != '0') {
      int tmp = stoi(x);
      if (tmp > val && tmp < res)
        res = tmp;
    }
  } while (next_permutation(x.begin(), x.end()));

  if (res == 1e9)
    cout << 0 << '\n';
  else
    cout << res << '\n';
}