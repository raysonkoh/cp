#include <iostream>
#include <map>
#include <vector>

using namespace std;

void print(vector<vector<int>> &m, vector<string> &v, int x) {
  cout << v[x];
  for (int i = 0; i < m[x].size(); i++) {
    print(m, v, m[x][i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<string> v(n);
  vector<vector<int>> m(n, vector<int>());
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v[i] = s;
  }

  if (n == 1) {
    cout << v[0] << endl;
    return 0;
  }

  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    m[a].push_back(b);
  }

  print(m, v, a);
  cout << endl;
}