#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

pair<string, int> getNextWord(string s, int indx) {
  string res = "";
  for (int i = indx; i < s.length(); i++) {
    if (s.at(i) == ' ') {
      return make_pair(res, i);
    } else {
      res.push_back(s.at(i));
    }
  }
  return make_pair(res, s.length());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    int n = stoi(s);
    if (n == 0) {
      break;
    }

    vector<string> foods;
    map<string, vector<string>> m;

    for (int i = 0; i < n; i++) {
      getline(cin, s);
      pair<string, int> p = getNextWord(s, 0);
      string name = p.first;
      // cout << "name: " << name << endl;
      int currIndx = p.second + 1;
      while (currIndx < s.length()) {
        p = getNextWord(s, currIndx);
        string food = p.first;
        // cout << "food: " << food << endl;
        if (m.find(food) == m.end()) {
          m[food] = vector<string>();
          foods.push_back(food);
        }
        m[food].push_back(name);
        currIndx = p.second;
        currIndx++;
      }
    }

    sort(foods.begin(), foods.end());
    for (int i = 0; i < foods.size(); i++) {
      cout << foods[i] << " ";
      vector<string> names = m[foods[i]];
      sort(names.begin(), names.end());
      for (int j = 0; j < names.size(); j++) {
        if (j == names.size() - 1) {
          cout << names[j];
        } else {
          cout << names[j] << " ";
        }
      }
      cout << endl;
    }
    cout << endl;
  }
}