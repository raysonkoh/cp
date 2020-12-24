#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    if (i == 0) {
      cout << v[i];
    } else {
      cout << " " << v[i];
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<int> v(5, 0);
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
  }
  while (true) {
    bool haschange = false;
    for (int i = 0; i < 4; i++) {
      if (v[i] > v[i + 1]) {
        haschange = true;
        swap(v[i], v[i + 1]);
        print(v);
      }
    }
    if (!haschange) {
      break;
    }
  }
}