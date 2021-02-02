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
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

long long convertToBase(vector<int> &v, int b) {
  long long res = 0;
  long long exp = 1;
  for (int i = v.size() - 1; i >= 0; i--) {
    int x = v[i];
    res += x * exp;
    exp *= b;
  }
  return res;
}

vector<int> convert(string s) {
  vector<int> v(s.length());
  for (int i = 0; i < s.length(); i++) {
    char c = s.at(i);
    int tmp;
    if (isalpha(c)) {
      tmp = c - 'a' + 10;
    } else {
      tmp = c - '0';
    }
    v[i] = tmp;
  }
  return v;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    string s1, cmd, s2, equal, s3;
    cin >> s1 >> cmd >> s2 >> equal >> s3;
    vector<int> v1 = convert(s1);
    vector<int> v2 = convert(s2);
    vector<int> v3 = convert(s3);
    auto maxEle1 = max_element(v1.begin(), v1.end());
    auto maxEle2 = max_element(v2.begin(), v2.end());
    auto maxEle3 = max_element(v3.begin(), v3.end());
    auto minEle1 = min_element(v1.begin(), v1.end());
    auto minEle2 = min_element(v2.begin(), v2.end());
    auto minEle3 = min_element(v3.begin(), v3.end());
    int maxEle = max({*maxEle1, *maxEle2, *maxEle3});
    int minEle = min({*minEle1, *minEle2, *minEle3});
    vector<int> res;
    if (maxEle == 1 && minEle == 1) {
      long long a = convertToBase(v1, 1);
      long long b = convertToBase(v2, 1);
      long long c = convertToBase(v3, 1);
      bool can;
      if (cmd == "+") {
        can = (a + b == c);
      } else if (cmd == "-") {
        can = (a - b == c);
      } else if (cmd == "*") {
        can = (a * b == c);
      } else if (cmd == "/") {
        can = (a % b == 0 && a / b == c);
      }
      if (can) {
        res.push_back(1);
      }
    }
    for (int i = maxEle + 1; i <= 36; i++) {
      long long a = convertToBase(v1, i);
      long long b = convertToBase(v2, i);
      long long c = convertToBase(v3, i);
      bool can;
      if (cmd == "+") {
        can = (a + b == c);
      } else if (cmd == "-") {
        can = (a - b == c);
      } else if (cmd == "*") {
        can = (a * b == c);
      } else if (cmd == "/") {
        can = (a % b == 0 && a / b == c);
      }
      if (can) {
        res.push_back(i);
      }
    }
    for (int x : res) {
      if (x < 10) {
        cout << x;
      } else if (x == 36) {
        cout << '0';
      } else {
        cout << (char)(x - 10 + 'a');
      }
    }
    if (res.size() == 0)
      cout << "invalid";
    cout << '\n';
  }
}
