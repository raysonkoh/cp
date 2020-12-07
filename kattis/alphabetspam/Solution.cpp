#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  string s;
  long numws = 0;
  long numlo = 0;
  long numup = 0;
  long numsym = 0;
  cin >> s;
  for (long i = 0; i < s.length(); i++) {
    int ascii = (int)s.at(i);
    if (ascii >= 97 && ascii <= 122) {
      numlo++;
    } else if (ascii >= 65 && ascii <= 90) {
      numup++;
    } else if (ascii == 95) {
      numws++;
    } else {
      numsym++;
    }
  }
  cout << fixed << setprecision(8);
  cout << ((double)numws) / ((double)s.length()) << endl;
  cout << ((double)numlo) / ((double)s.length()) << endl;
  cout << ((double)numup) / ((double)s.length()) << endl;
  cout << ((double)numsym) / ((double)s.length()) << endl;
  return 0;
}