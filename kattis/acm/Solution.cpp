#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
  int res = 0;
  int correctCount = 0;
  map<char, int> wrongCount;
  set<int> correct;
  int m;
  char c;
  string s;

  while (cin >> m >> c >> s) {
    if (s == "right") {
      if (correct.find(c) != correct.end()) {
        continue;
      }
      correctCount++;
      if (wrongCount.find(c) == wrongCount.end()) {
        res += m;
      } else {
        res += m + 20 * wrongCount.find(c)->second;
      }
    } else {
      if (wrongCount.find(c) == wrongCount.end()) {
        wrongCount[c] = 1;
      } else {
        wrongCount[c]++;
      }
    }
  }
  cout << correctCount << " " << res << endl;
  return 0;
}