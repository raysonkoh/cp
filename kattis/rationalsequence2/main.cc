#include <iostream>

using namespace std;

int getSeqNum(int p, int q) {
  if (p == 1 && q == 1) {
    return 1;
  }

  if (p < q) {
    return 2 * getSeqNum(p, q - p);
  } else {
    return 2 * getSeqNum(p - q, q) + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int p;
  cin >> p;
  while (p--) {
    int k;
    cin >> k;
    cout << k << " ";
    string s;
    cin >> s;
    auto it = s.find("/");
    string a = s.substr(0, it);
    string b = s.substr(it + 1, s.length() - 1 - a.length());
    cout << getSeqNum(stoi(a), stoi(b)) << "\n";
  }
}