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

// convert s to decimal
long long decode(string s, string lang) {
  long long res = 0;
  int curr = 1;
  int n = lang.length();
  for (int i = s.length() - 1; i >= 0; i--) {
    int indx = lang.find(s.at(i));
    // cout << "indx: " << indx << " exp: " << curr << endl;
    res += indx * curr;
    curr *= n;
  }
  return res;
}

// encode decimal x to lang
string encode(long long x, string lang) {
  string res = "";
  int n = lang.length();
  while (x > 0) {
    res.insert(res.begin(), lang.at(x % n));
    x /= n;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  int caseNum = 1;
  while (t--) {
    string num, src, tar;
    cin >> num >> src >> tar;
    long long x = decode(num, src);
    string res = encode(x, tar);
    cout << "Case #" << caseNum << ": " << res << '\n';
    caseNum++;
  }
}