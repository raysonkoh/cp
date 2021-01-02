#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v{2, 1, 3};
  sort(v.begin(), v.end());
  do {
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
  } while (next_permutation(v.begin(), v.end()));
  cout << "after " << v[0] << " " << v[1] << " " << v[2] << endl;
}