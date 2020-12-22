#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string x;
    cin >> x;
    if (x != "mumble") {
      if (stoi(x) != i) {
        cout << "something is fishy" << endl;
        return 0;
      }
    }
  }
  cout << "makes sense" << endl;
}