#include <iostream>

using namespace std;

pair<string, int> getNextWord(string s, int st) {
  string res = "";
  for (int i = st; i < s.length(); i++) {
    char c = s.at(i);
    if (c == ':') {
      return make_pair(res, i);
    }
    res.push_back(c);
  }
  return make_pair(res, s.length());
}

int parseTime(string s) {
  auto [hr, i] = getNextWord(s, 0);
  auto [min, j] = getNextWord(s, i + 1);
  auto [sec, k] = getNextWord(s, j + 1);
  return stoi(hr) * 3600 + stoi(min) * 60 + stoi(sec);
}

void pad(string &s) {
  while (s.length() < 2) {
    s.insert(s.begin(), '0');
  }
}

string getTime(int diff) {
  int hr = 0;
  int min = 0;
  int sec = 0;
  if (diff / 3600 > 0) {
    hr = diff / 3600;
    diff = diff % 3600;
  }
  if (diff / 60 > 0) {
    min = diff / 60;
    diff = diff % 60;
  }
  if (diff > 0) {
    sec = diff;
  }
  string h = to_string(hr);
  pad(h);
  string m = to_string(min);
  pad(m);
  string s = to_string(sec);
  pad(s);
  return h + ":" + m + ":" + s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s1;
  string s2;
  cin >> s1 >> s2;
  int s1Time = parseTime(s1);
  int s2Time = parseTime(s2);
  int diff = s2Time - s1Time;
  if (diff <= 0)
    diff += 3600 * 24;
  cout << getTime(diff) << endl;
}