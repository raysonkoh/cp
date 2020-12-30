#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string p;
    cin >> p;
    int n;
    cin >> n;
    vector<int> v(n);
    char c;
    cin >> c; // account for '['
    for (int i = 0; i < n; i++) {
      string numStr = "";
      cin >> c;

      while (true) {
        if (c == ',' || c == ']') {
          break;
        }
        numStr.push_back(c);
        cin >> c;
      }

      v[i] = stoi(numStr);
    }

    if (n == 0)
      cin >> c; // account for ']'

    int st = 0;
    int ed = n - 1;
    int numEle = n;
    bool foundError = false;

    for (char ch : p) {
      if (ch == 'R') {
        swap(st, ed);
      } else {
        // D
        if (numEle == 0) {
          foundError = true;
          cout << "error\n";
          break;
        }
        numEle--;
        if (st <= ed) {
          st++;
        } else {
          st--;
        }
      }
    }

    if (!foundError) {
      cout << "[";
      if (numEle > 0) {

        if (st < ed) {
          for (int i = st; i <= ed; i++) {
            cout << v[i];
            if (i < ed) {
              cout << ",";
            }
          }
        } else {
          for (int i = st; i >= ed; i--) {
            cout << v[i];
            if (i > ed) {
              cout << ",";
            }
          }
        }
      }
      cout << "]\n";
    }
  }
}