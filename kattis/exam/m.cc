#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int k;
  cin >> k;
  string s1;
  getline(cin, s1);
  getline(cin, s1);
  string s2;
  getline(cin, s2);

  int n = s1.length();
  int w = n - k;
  int currCorrect = 0;
  int currWrong = 0;
  int score = 0;

  for (int i = 0; i < n; i++) {
    char c1 = s1.at(i);
    char c2 = s2.at(i);
    if (c1 == c2) {
      if (currCorrect < k) {
        currCorrect++;
        score++;
      } else {
        currWrong++;
      }
    } else {
      if (currWrong < w) {
        currWrong++;
        score++;
      } else {
        currCorrect++;
      }
    }
  }
  cout << score << '\n';
}