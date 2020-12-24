#include <iostream>

using namespace std;

void print(string s) {
  if (s.length() == 0) {
    cout << "YODA" << endl;
  } else {
    cout << (s.at(0) == '0' ? "0" : s) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string n, m;
  cin >> n >> m;
  string nres = "";
  string mres = "";
  bool hasSwap = false;
  if (n.length() > m.length()) {
    hasSwap = true;
    swap(n, m);
  }

  int nindx = n.length() - 1;
  int mindx = m.length() - 1;
  while (nindx >= 0) {
    int cn = n.at(nindx) - '0';
    int cm = m.at(mindx) - '0';
    if (cn < cm) {
      mres.insert(mres.begin(), m.at(mindx));
    } else if (cn > cm) {
      nres.insert(nres.begin(), n.at(nindx));
    } else {
      mres.insert(mres.begin(), m.at(mindx));
      nres.insert(nres.begin(), n.at(nindx));
    }
    nindx--;
    mindx--;
  }
  while (mindx >= 0) {
    mres.insert(mres.begin(), m.at(mindx));
    mindx--;
  }

  if (hasSwap) {
    swap(nres, mres);
  }

  print(nres);
  print(mres);
}