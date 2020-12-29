#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {1, 2, 3};
  auto it = lower_bound(v.begin(), v.end(), 0);
  cout << *it << endl;            // 1
  cout << it - v.begin() << endl; // 0
  it = lower_bound(v.begin(), v.end(), 2);
  cout << *it << endl;            // 2
  cout << it - v.begin() << endl; // 1
}