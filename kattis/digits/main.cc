#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  // for (int i = 0; i < 1000000; i++) {
  //  s.push_back('1');
  //}

  while (cin >> s) {
    if (s == "END") {
      break;
    }

    if (s.length() == 1 && stoi(s) == 1) {
      cout << 1 << endl;
    } else {
      int prev = s.length();
      string next = to_string(to_string(prev).length());
      int indx = 2;
      while (prev != next.length()) {
        // cout << "indx: " << indx << " prev: " << prev << " next: " << next
        //     << endl;
        prev = stoi(next);
        next = to_string(next.length());
        indx++;
      }
      cout << indx << endl;
    }
  }
}