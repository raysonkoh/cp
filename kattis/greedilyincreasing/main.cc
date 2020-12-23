#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v;
  int curr;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i == 0) {
      count++;
      curr = x;
      v.push_back(x);
    } else {
      if (x > curr) {
        count++;
        curr = x;
        v.push_back(x);
      }
    }
  }
  cout << count << endl;
  for (int i = 0; i < v.size(); i++) {
    if (i == 0) {
      cout << v[i];
    } else {
      cout << " " << v[i];
    }
  }
  cout << endl;
}