#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int num = 1;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    vector<string> fr;
    vector<string> ba;
    cout << "SET " << num << endl;
    for (int i = 0; i < n / 2; i++) {
      string s1, s2;
      cin >> s1 >> s2;
      fr.push_back(s1);
      ba.push_back(s2);
    }
    if (n % 2 == 1) {
      string s;
      cin >> s;
      fr.push_back(s);
    }

    for (int i = 0; i < fr.size(); i++) {
      cout << fr[i] << endl;
    }

    for (int i = ba.size() - 1; i >= 0; i--) {
      cout << ba[i] << endl;
    }

    num++;
  }
  return 0;
}