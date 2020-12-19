#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b, c;
  cin >> a >> b >> c;

  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  sort(v.begin(), v.end());
  int firstdiff = v[1] - v[0];
  int seconddiff = v[2] - v[1];
  if (firstdiff == seconddiff) {
    cout << v[2] + firstdiff << endl;
  } else if (firstdiff > seconddiff) {
    cout << v[1] - seconddiff << endl;
  } else {
    cout << v[1] + firstdiff << endl;
  }
}