#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  if (s1.length() > s2.length()) {
    swap(s1, s2);
  }

  vector<int> v(s2.length() + 1, 0);
  int carry = 0;
  for (int i = 0; i < v.size(); i++) {
    int c1, c2;
    if (i >= s1.length()) {
      c1 = 0;
    } else {
      c1 = s1.at(s1.length() - 1 - i) - '0';
    }
    if (i >= s2.length()) {
      c2 = 0;
    } else {
      c2 = s2.at(s2.length() - 1 - i) - '0';
    }
    int sum = c1 + c2 + carry;
    carry = sum / 10;
    int remain = sum % 10;
    v[i] = remain;
  }
  int start;
  if (v[s2.length()] == 0) {
    start = s2.length() - 1;
  } else {
    start = s2.length();
  }
  for (int i = start; i >= 0; i--) {
    cout << v[i];
  }
  cout << endl;
}