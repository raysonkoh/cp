#include <iostream>
#include <vector>

using namespace std;

char getCounter(char ch) {
  if (ch == 'R') {
    return 'S';
  } else if (ch == 'B') {
    return 'K';
  } else {
    return 'H';
  }
}

vector<char> replaceV(vector<char> &v, char c) {
  vector<char> res;
  int indx = -1;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == c) {
      indx = i;
    }
  }

  if (indx == -1) {
    // means c not present in v, can safely push to v
    for (int i = 0; i < v.size(); i++) {
      res.push_back(v[i]);
    }
  } else {
    // c present in v, pop all indxes <= indx
    for (int i = 0; i <= indx; i++) {
      cout << getCounter(v[i]);
    }
    for (int i = indx + 1; i < v.size(); i++) {
      res.push_back(v[i]);
    }
  }
  res.push_back(c);
  return res;
}

bool findInV(vector<char> &v, char c) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == c) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  char c;
  vector<char> v;
  while (cin >> c) {
    // cout << "curren char: " << c << endl;
    v = replaceV(v, c);
    if (findInV(v, 'R') && findInV(v, 'B') && findInV(v, 'L')) {
      // cout << "pop all" << endl;
      cout << 'C';
      v.clear();
    }
  };
  for (int i = 0; i < v.size(); i++) {
    char ch = v[i];
    cout << getCounter(ch);
  }
  cout << endl;
}