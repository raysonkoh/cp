#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<double> v(205025);
void init() {
  for (int i = 1; i <= 205024; i++) {
    if (i == 1)
      v[i] = log10(i);
    else
      v[i] = v[i - 1] + log10(i);
  }
}

void convertToDigit() {
  for (int i = 1; i <= 205024; i++) {
    v[i] = ((int)v[i]) + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  convertToDigit();
  map<int, int> edgeCases;
  edgeCases[720] = 6;
  edgeCases[120] = 5;
  edgeCases[24] = 4;
  edgeCases[6] = 3;
  edgeCases[2] = 2;
  edgeCases[1] = 1;

  string s;
  getline(cin, s);
  int numDigits = s.length();
  if (numDigits <= 3) {
    cout << edgeCases[stoi(s)] << "\n";
  } else {
    cout << lower_bound(v.begin(), v.end(), numDigits) - v.begin() << "\n";
  }
}
