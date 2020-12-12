#include <iostream>
#include <map>

using namespace std;

int main() {
  int t;
  cin >> t;

  string s;
  getline(cin, s);
  for (int i = 0; i < t; i++) {
    getline(cin, s);
    map<string, string> m;
    string l;
    while (getline(cin, l)) {
      if (l == "what does the fox say?") {
        bool isFirst = true;
        string word = "";
        for (int j = 0; j < s.length(); j++) {
          if (s.at(j) == ' ') {
            if (m.find(word) == m.end()) {
              if (isFirst) {
                isFirst = false;
              } else {
                cout << " ";
              }
              cout << word;
            }
            word = "";
          } else {
            word.push_back(s.at(j));
          }
        }
        if (word.length() > 0 && m.find(word) == m.end()) {
          if (isFirst) {
            isFirst = false;
          } else {
            cout << " ";
          }
          cout << word;
        }
        cout << endl;
        break;
      }
      string animal = "";
      string sound = "";
      bool isAnimal = true;
      int indx = 0;
      while (indx < l.length()) {
        if (l.substr(indx, 6) == " goes ") {
          indx += 6;
          isAnimal = false;
        } else if (isAnimal) {
          animal.push_back(l.at(indx));
          indx++;
        } else {
          sound.push_back(l.at(indx));
          indx++;
        }
      }
      // cout << animal << " : " << sound << endl;
      m[sound] = animal;
    };
  }
  return 0;
}
