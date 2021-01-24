#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string cipher, secret;
  cin >> cipher >> secret;

  int i = 0;
  int j = 0;
  string tmp = "";
  while (i < cipher.length()) {
    if (j == secret.length()) {
      cout << tmp;
      secret = tmp;
      tmp = "";
      j = 0;
    }

    int shift = secret.at(j) - 'A';
    int ascii = cipher.at(i);
    ascii -= shift;
    if (ascii < 65)
      ascii += 26;
    tmp.push_back((char)ascii);

    i++;
    j++;
  }
  cout << tmp << '\n';
}
