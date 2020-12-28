#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long p = 29996224275833;
long long base = 256;

class RabinKarp {
public:
  string pattern;
  string text;
  long long msb;
  RabinKarp(string pat, string txt) : pattern(pat), text(txt) {
    msb = 1;
    for (int i = 1; i < pat.length(); i++) {
      msb = (msb * base) % p;
    }
  }

  long long generateHash(string s, int start, int len) {
    long long res = 0;
    for (int i = start; i < start + len; i++) {
      res = (res * base + (long long)s.at(i)) % p;
    }
    return res;
  }

  long long rollHash(long long oldHash, string s, int deleteIndx, int addIndx) {
    // cout << "old: " << oldHash << endl;
    return (base * (oldHash - ((long long)s.at(deleteIndx) * msb)) +
            (long long)s.at(addIndx)) %
           p;
  }

  bool checkEq(string a, int s1, int e1, string b, int s2, int e2) {
    if (e1 - s1 != e2 - s2) {
      return false;
    }
    while (s1 <= e1 && s2 <= e2) {
      if (a[s1] != b[s2]) {
        return false;
      }
      s1++;
      s2++;
    }
    return true;
  }

  void run() {
    long long patHash = generateHash(pattern, 0, pattern.length());
    long long textHash = generateHash(text, 0, pattern.length());
    bool isFirst = true;
    for (int i = 0; i <= text.length() - pattern.length(); i++) {
      if (patHash == textHash && checkEq(pattern, 0, pattern.length() - 1, text,
                                         i, i + pattern.length() - 1)) {
        // found match
        if (isFirst) {
          isFirst = false;
        } else {
          cout << " ";
        }
        cout << i;
      }
      if (i < text.length() - pattern.length()) {
        textHash = rollHash(textHash, text, i, i + pattern.length());
        if (textHash < 0) {
          textHash += p;
        }
      }
    }
  }
};

int main() {
  string pat;
  while (getline(cin, pat)) {
    string txt;
    getline(cin, txt);
    RabinKarp rabinKarp(pat, txt);
    rabinKarp.run();
    cout << "\n";
  }
}
