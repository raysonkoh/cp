#include <iostream>
#include <vector>

using namespace std;

// O((2^n) * n), can be faster with meet in middle method (i.e. splitting array into 2)
class PowerSet {
public:
  vector<int> v;
  PowerSet(vector<int> &vect) : v(vect) {}
  void run() {
    int n = v.size();
    int maxSize = 1 << n;
    for (int i = 0; i < maxSize; i++) {
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          // include in set
          cout << v[j] << " ";
        }
      }
      cout << '\n';
    }
  }
};

int main() {
  vector<int> v{1, 2, 3};
  PowerSet ps(v);
  ps.run();
}