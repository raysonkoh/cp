#include <iostream>

using namespace std;

class Test {
public:
  Test(int x, int y) {
    a = x;
    b = y;
  }
  void print() { cout << "a: " << a << " b: " << b << endl; }

private:
  int a;
  const int b;
};

int main() {
  Test t(1, 2);
  t.print();
}
