#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

class KMP {
public:
  vector<int> lps;
  string pattern;
  string text;
  KMP(string pat, string txt) : pattern(pat), text(txt) {
    lps.assign(pattern.length(), 0);
    calcLPS();
  }
  void calcLPS() {
    int i = 1;   // pointer to current element
    int len = 0; // current length of longest prefix-suffix match
    while (i < lps.size()) {
      // if pattern is same, length of longest prefix-suffix match is len + 1
      if (pattern[i] == pattern[len]) {
        lps[i] = len + 1;
        i++;
        len++;
      } else {
        if (len > 0) {
          // if current length of longest prefix-suffix match is greater than 0,
          // then length of longest prefix-suffix can be length of longest
          // prefix-suffix at lps[len - 1]
          len = lps[len - 1];
        } else {
          // if current length of longest prefix-suffix match is 0 and no match,
          // then length of longest prefix-suffix is 0
          lps[i] = 0;
          i++;
        }
      }
    }
  }
  void calcOccurences() {
    int n = text.length();
    int m = pattern.length();
    int i = 0; // text pointer
    int j = 0; // pattern pointer
    while (i < n) {
      if (text[i] == pattern[j]) {
        i++;
        j++;
      } else {
        if (j > 0) {
          j = lps[j - 1];
        } else {
          i++;
        }
      }
      if (j == m) {
        j = lps[j - 1];
        cout << i - m << " ";
      }
    }
    cout << endl;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    string txt;
    getline(cin, txt);
    KMP kmp(s, txt);
    kmp.calcOccurences();
  }
}