#include <iostream>
#include <set>

using namespace std;

template <class T> class Test {
public:
  T first;
  Test(char x) : first(x) {}
  Test(T x) : first(x) {}
};

int main() {
  set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  set<int> s2;
  s2.insert(4);
  s2.insert(5);
  s2.insert(3);
  s.merge(s2);
  for (int i = 1; i <= 6; i++) {
    cout << (s.find(i) == s.end()) << endl; // should be 0
  }
  // Test<int> t(5);
  // cout << t.first << endl;
  // Test<char> d('a');
  // cout << d.first << endl;
}
