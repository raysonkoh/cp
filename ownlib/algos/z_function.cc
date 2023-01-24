#include <string>
#include <vector>

using namespace std;

// z[i]: max number of characters starting from s_i that matches prefix
// https://cp-algorithms.com/string/z-function.html
class Zf {
public:
  vector<int> z;
  int n;

  Zf(int sz) {
    n = sz;
    z.resize(n);
  }

  void run(string &s) {
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
      if (i <= r)
        z[i] = min(r - i + 1, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
      if (i + z[i] - 1 > r)
        l = i, r = i + z[i] - 1;
    }
  }
};
