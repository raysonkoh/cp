#include <iostream>
#include <string>
#include <vector>

using namespace std;

long partOne(vector<long> v, bool debug) {
  for (int i = 0; i < v.size(); i += 4) {
    int opcode = v[i];
    if (opcode == 99) {
      break;
    }
    long a = v[i + 1];
    long b = v[i + 2];
    long c = v[i + 3];
    if (opcode == 1) {
      v[c] = v[a] + v[b];
    } else if (opcode == 2) {
      v[c] = v[a] * v[b];
    }
  }
  if (debug) {
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << endl;
    }
  } else {
    // cout << v[0] << endl;
  }
  return v[0];
}

int main() {
  bool debug = false;
  string s;
  cin >> s;
  vector<long> v;
  string tmp = "";
  for (int i = 0; i < s.length(); i++) {
    char c = s.at(i);
    if (c == ',') {
      v.push_back(stol(tmp));
      tmp = "";
    } else {
      tmp.push_back(c);
    }
  }

  if (tmp != "") {
    v.push_back(stol(tmp));
  }

  /* part 1
  v[1] = 12;
  v[2] = 2;
  long res = partOne(v, debug);
  cout << res << endl;
  */

  for (int i = 0; i < 99; i++) {
    for (int j = 0; j < 99; j++) {
      vector<long> tempV;
      for (int k = 0; k < v.size(); k++) {
        tempV.push_back(v[k]);
      }
      tempV[1] = i;
      tempV[2] = j;
      long res = partOne(tempV, debug);
      if (res == 19690720) {
        cout << "ans: " << i * 100 + j << endl;
      }
    }
  }

  return 0;
}