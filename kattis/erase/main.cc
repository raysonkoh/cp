#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s1, s2;
  getline(cin, s1);
  getline(cin, s1);
  getline(cin, s2);
  n = n % 2;
  if (n == 0) {
    if (s1 == s2) {
      cout << "Deletion succeeded" << endl;
    } else {
      cout << "Deletion failed" << endl;
    }
  } else {
    for (int i = 0; i < s1.length(); i++) {
      if ((s1[i] ^ s2[i]) == 0) {
        cout << "Deletion failed" << endl;
        return 0;
      }
    }
    cout << "Deletion succeeded" << endl;
  }
}