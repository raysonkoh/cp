#include <iostream>
#include <vector>

using namespace std;

vector<string> permute(string s) {
  // cout << "permuting " << s << endl;
  if (s == "")
    return {s};

  vector<string> res;
  for (int i = 0; i < s.length(); i++) {
    string tmp = s;
    tmp.erase(i, 1);
    vector<string> tmpV = permute(tmp);
    for (int j = 0; j < tmpV.size(); j++) {
      // cout << "before " << tmp << endl;
      tmp = tmpV[j];
      tmp.insert(tmp.begin(), s[i]);
      // cout << "after " << tmp << endl;
      res.push_back(tmp);
    }
  }
  // cout << "end permuting " << s << endl;
  return res;
}

int main() {
  string s = "abcd";
  vector<string> res = permute(s);
  cout << res.size() << endl;
  for (string a : res)
    cout << a << endl;
}