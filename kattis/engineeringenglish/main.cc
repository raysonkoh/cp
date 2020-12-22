#include <iostream>
#include <set>
#include <string>

using namespace std;

pair<string, int> nextWord(string s, int start) {
  string res = "";
  for (int i = start; i < s.length(); i++) {
    if (s.at(i) == ' ') {
      return make_pair(res, i);
    } else {
      res.push_back(s.at(i));
    }
  }
  return make_pair(res, s.length() - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  set<string> s;
  string str;
  while (getline(cin, str)) {
    int indx = 0;
    bool isFirst = true;
    while (indx < str.length()) {
      if (isFirst) {
        isFirst = false;
      } else {
        cout << " ";
      }
      pair<string, int> p = nextWord(str, indx);
      string word = p.first;
      string lowerWord = "";
      for (int i = 0; i < word.length(); i++) {
        lowerWord.push_back(tolower(word[i]));
      }
      if (s.find(lowerWord) == s.end()) {
        s.insert(lowerWord);
        cout << word;
      } else {
        cout << ".";
      }
      indx = p.second + 1;
    }
    cout << endl;
  }
}