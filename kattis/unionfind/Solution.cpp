#include <iostream>

using namespace std;

class ufds {
public:
  void print() { cout << "hello world!" << endl; }
};

int main() {
  long long n, q;
  for (long long i = 0; i < q; i++) {
    char c;
    long long a, b;
    cin >> c >> a >> b;
    if (c == '?') {
      // query
    } else {
      // merge
    }
  }

  ufds u;
  u.print();
  return 0;
}