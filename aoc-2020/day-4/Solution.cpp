#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool validate(string val, string key) {
  if (key == "byr") {
    return val.length() == 4 && stoi(val) >= 1920 && stoi(val) <= 2002;
  } else if (key == "iyr") {
    return val.length() == 4 && stoi(val) >= 2010 && stoi(val) <= 2020;
  } else if (key == "eyr") {
    return val.length() == 4 && stoi(val) >= 2020 && stoi(val) <= 2030;
  } else if (key == "hgt") {
    string numStr = "";

    for (int i = 0; i < val.length(); i++) {
      char c = val.at(i);
      if (c == 'c') {
        int num = stoi(numStr);
        return num >= 150 && num <= 193;
      } else if (c == 'i') {
        int num = stoi(numStr);
        return num >= 59 && num <= 76;
      } else {
        numStr.push_back(c);
      }
    }

    return false;
  } else if (key == "hcl") {
    if (val.at(0) != '#' || val.length() != 7) {
      return false;
    }
    for (int i = 1; i < 7; i++) {
      int ascii = (int)val.at(i);
      if ((!(ascii >= 48 && ascii <= 57)) && (!(ascii >= 97 && ascii <= 102))) {
        return false;
      }
    }
    return true;
  } else if (key == "ecl") {
    return val == "amb" || val == "blu" || val == "brn" || val == "gry" ||
           val == "grn" || val == "hzl" || val == "oth";
  } else if (key == "pid") {
    return val.length() == 9;
  }
  return false;
}

void test() {
  cout << validate("2002", "byr") << endl;
  cout << validate("2003", "byr") << endl;
  cout << "" << endl;

  cout << validate("60in", "hgt") << endl;
  cout << validate("190cm", "hgt") << endl;
  cout << validate("190in", "hgt") << endl;
  cout << validate("190", "hgt") << endl;
  cout << "" << endl;

  cout << validate("#123abc", "hcl") << endl;
  cout << validate("#123abz", "hcl") << endl;
  cout << validate("123abc", "hcl") << endl;
  cout << "" << endl;

  cout << validate("brn", "ecl") << endl;
  cout << validate("wat", "ecl") << endl;
  cout << "" << endl;

  cout << validate("000000001", "pid") << endl;
  cout << validate("0123456789", "pid") << endl;
}

int main() {
  // test();
  int n = 1147;
  vector<map<string, string>> v;
  int idx = 0;

  for (int i = 0; i < n; i++) {
    string tmp;
    getline(cin, tmp);
    if (tmp == "") {
      // cout << "" << endl;
      idx++;
    } else {
      map<string, string> m;
      v.push_back(m);

      bool isKey = true;
      string key = "";
      string val = "";
      for (int j = 0; j < tmp.length(); j++) {
        char c = tmp.at(j);
        if (c == ' ') {
          v[idx][key] = val;
          // cout << key << " : " << val << endl;
          key = "";
          val = "";
          isKey = true;
          continue;
        }

        if (c == ':') {
          isKey = false;
          continue;
        }

        if (isKey) {
          key.push_back(c);
        } else {
          val.push_back(c);
        }
      }
      v[idx][key] = val;
      // cout << key << " : " << val << endl;
      key = "";
      val = "";
      isKey = true;
    }
  }
  vector<string> reqFields;
  reqFields.push_back("byr");
  reqFields.push_back("iyr");
  reqFields.push_back("eyr");
  reqFields.push_back("hgt");
  reqFields.push_back("hcl");
  reqFields.push_back("ecl");
  reqFields.push_back("pid");

  int res = 0;
  for (int i = 0; i < v.size(); i++) {
    bool isValid = true;
    for (int j = 0; j < reqFields.size(); j++) {
      if ((v[i].find(reqFields[j]) == v[i].end()) ||
          (!validate(v[i].find(reqFields[j])->second, reqFields[j]))) {
        isValid = false;
        break;
      }
    }
    if (isValid) {
      // cout << i << endl;
      res++;
    }
  }
  cout << res << endl;
  return 0;
}