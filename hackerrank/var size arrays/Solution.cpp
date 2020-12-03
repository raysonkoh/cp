#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> v;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    vector<int> tmpV;
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int tmp;
      cin >> tmp;
      tmpV.push_back(tmp);
    }
    v.push_back(tmpV);
  }

  for (int i = 0; i < q; i++) {
    int first, second;
    cin >> first >> second;
    cout << v[first][second] << endl;
  }

  return 0;
}