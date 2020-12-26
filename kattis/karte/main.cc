#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  set<int> p;
  set<int> k;
  set<int> h;
  set<int> t;
  for (int i = 0; i < s.length(); i += 3) {
    char suit = s.at(i);
    int num = stoi(s.substr(i + 1, 2));
    switch (suit) {
    case 'P':
      if (p.find(num) == p.end()) {
        p.insert(num);
      } else {
        cout << "GRESKA" << endl;
        return 0;
      }
      break;
    case 'K':
      if (k.find(num) == k.end()) {
        k.insert(num);
      } else {
        cout << "GRESKA" << endl;
        return 0;
      }
      break;
    case 'H':
      if (h.find(num) == h.end()) {
        h.insert(num);
      } else {
        cout << "GRESKA" << endl;
        return 0;
      }
      break;
    case 'T':
      if (t.find(num) == t.end()) {
        t.insert(num);
      } else {
        cout << "GRESKA" << endl;
        return 0;
      }
      break;
    }
  }
  cout << 13 - p.size() << " " << 13 - k.size() << " " << 13 - h.size() << " "
       << 13 - t.size() << endl;
}