#include <iostream>
#include <map>
#include <vector>

using namespace std;

string getop(int i) {
  if (i == 0) {
    return " + ";
  } else if (i == 1) {
    return " - ";
  } else if (i == 2) {
    return " * ";
  } else {
    return " / ";
  }
}

string constructeqn(int i, int j, int k) {
  string res = "4";
  res.append(getop(i));
  res.push_back('4');
  res.append(getop(j));
  res.push_back('4');
  res.append(getop(k));
  res.push_back('4');
  return res;
}

int main() {
  int t;
  cin >> t;
  map<int, string> m;
  // + : 0
  // - : 1
  // * : 2
  // / : 3

  // first
  m[16] = constructeqn(0, 0, 0);
  m[8] = constructeqn(0, 0, 1);
  m[24] = constructeqn(0, 0, 2);
  m[9] = constructeqn(0, 0, 3);

  m[8] = constructeqn(0, 1, 0);
  m[0] = constructeqn(0, 1, 1);
  m[-8] = constructeqn(0, 1, 2);
  m[7] = constructeqn(0, 1, 3);

  m[24] = constructeqn(0, 2, 0);
  m[16] = constructeqn(0, 2, 1);
  m[68] = constructeqn(0, 2, 2);
  m[8] = constructeqn(0, 2, 3);

  m[9] = constructeqn(0, 3, 0);
  m[1] = constructeqn(0, 3, 1);
  m[8] = constructeqn(0, 3, 2);
  m[4] = constructeqn(0, 3, 3);

  // second
  m[8] = constructeqn(1, 0, 0);
  m[0] = constructeqn(1, 0, 1);
  m[16] = constructeqn(1, 0, 2);
  m[1] = constructeqn(1, 0, 3);

  m[0] = constructeqn(1, 1, 0);
  m[-8] = constructeqn(1, 1, 1);
  m[-16] = constructeqn(1, 1, 2);
  m[-1] = constructeqn(1, 1, 3);

  m[-8] = constructeqn(1, 2, 0);
  m[-16] = constructeqn(1, 2, 1);
  m[-60] = constructeqn(1, 2, 2);
  m[0] = constructeqn(1, 2, 3);

  m[7] = constructeqn(1, 3, 0);
  m[-1] = constructeqn(1, 3, 1);
  m[0] = constructeqn(1, 3, 2);
  m[4] = constructeqn(1, 3, 3);

  // third
  m[24] = constructeqn(2, 0, 0);
  m[16] = constructeqn(2, 0, 1);
  m[32] = constructeqn(2, 0, 2);
  m[17] = constructeqn(2, 0, 3);

  m[16] = constructeqn(2, 1, 0);
  m[8] = constructeqn(2, 1, 1);
  m[0] = constructeqn(2, 1, 2);
  m[15] = constructeqn(2, 1, 3);

  m[68] = constructeqn(2, 2, 0);
  m[60] = constructeqn(2, 2, 1);
  m[256] = constructeqn(2, 2, 2);
  m[16] = constructeqn(2, 2, 3);

  m[8] = constructeqn(2, 3, 0);
  m[0] = constructeqn(2, 3, 1);
  m[16] = constructeqn(2, 3, 2);
  m[1] = constructeqn(2, 3, 3);

  // fourth
  m[9] = constructeqn(3, 0, 0);
  m[1] = constructeqn(3, 0, 1);
  m[17] = constructeqn(3, 0, 2);
  m[2] = constructeqn(3, 0, 3);

  m[1] = constructeqn(3, 1, 0);
  m[-7] = constructeqn(3, 1, 1);
  m[-15] = constructeqn(3, 1, 2);
  m[0] = constructeqn(3, 1, 3);

  m[8] = constructeqn(3, 2, 0);
  m[0] = constructeqn(3, 2, 1);
  m[16] = constructeqn(3, 2, 2);
  m[1] = constructeqn(3, 2, 3);

  m[4] = constructeqn(3, 3, 0);
  m[-4] = constructeqn(3, 3, 1);
  // m[1] = constructeqn(3, 3, 2);
  m[0] = constructeqn(3, 3, 3);

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    if (m.find(n) == m.end()) {
      cout << "no solution" << endl;
    } else {
      cout << m.find(n)->second << " = " << n << endl;
    }
  }
  return 0;
}
