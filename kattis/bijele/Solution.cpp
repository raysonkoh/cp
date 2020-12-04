#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  v.push_back(1);
  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  v.push_back(2);
  v.push_back(8);

  for (int i = 0; i < 6; i++) {
    int tmp;
    cin >> tmp;
    v[i] -= tmp;
  }

  for (int i = 0; i < 6; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}