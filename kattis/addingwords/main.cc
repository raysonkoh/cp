#include <iostream>
#include <map>

using namespace std;

pair<string, int> getNextWord(string s, int st) {
  string res = "";
  int currindx = st;
  while (currindx < s.length() && s.at(currindx) != ' ') {
    res.push_back(s.at(currindx));
    currindx++;
  }
  return make_pair(res, currindx);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  map<string, int> strToInt;
  map<int, string> intToStr;
  while (getline(cin, s)) {
    pair<string, int> p = getNextWord(s, 0);
    string cmd = p.first;
    if (cmd == "def") {
      pair<string, int> pa = getNextWord(s, p.second + 1);
      pair<string, int> pb = getNextWord(s, pa.second + 1);
      string a = pa.first;
      int b = stoi(pb.first);

      if (strToInt.find(a) != strToInt.end()) {
        // redifinition
        intToStr.erase(strToInt[a]);
      }
      strToInt[a] = b;
      intToStr[b] = a;

    } else if (cmd == "calc") {
      int res = 0;
      string a, sign = "+";
      pair<string, int> pa = getNextWord(s, p.second + 1);
      a = pa.first;
      int lastindx = pa.second;

      bool end = false;
      while (sign != "=") {
        // cout << sign << a << endl;
        if (strToInt.find(a) == strToInt.end()) {
          cout << s.substr(5, s.length() - 5) << " unknown" << endl;
          end = true;
          break;
        } else if (sign == "+") {
          res += strToInt[a];
        } else {
          res -= strToInt[a];
        }

        pair<string, int> ps = getNextWord(s, lastindx + 1);
        lastindx = ps.second;
        pa = getNextWord(s, lastindx + 1);
        lastindx = pa.second;

        sign = ps.first;
        a = pa.first;
      }

      if (!end) {
        if (intToStr.find(res) == intToStr.end()) {
          cout << s.substr(5, s.length() - 5) << " unknown" << endl;
        } else {
          cout << s.substr(5, s.length() - 5) << " " << intToStr[res] << endl;
        }
      }

    } else {
      // clear
      strToInt.clear();
      intToStr.clear();
    }
  }
}