#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  bool found = false;
  bool isFirst = true;
  for (int i = 0; i < 5; i++) {
    getline(cin, s);
    if (s.find("FBI") < s.length()) {
      if (isFirst) {
        isFirst = false;
      } else {
        cout << " ";
      }
      cout << i + 1;
      found = true;
    }
  }
  if (!found) {
    cout << "HE GOT AWAY!" << endl;
  } else {
    cout << endl;
  }
}