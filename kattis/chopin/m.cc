#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-9;

using namespace std;

bool isLegal(string s) {
  set<string> ss{"Ab minor", "A# major", "A# minor", "C# major", "Db minor", "D# major", "D# minor", "Gb major", "Gb minor", "G# major"};
  return ss.find(s) == ss.end();
}

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  map<string, string> memo;
  memo["A#"] = "Bb";
  memo["Bb"] = "A#";
  memo["C#"] = "Db";
  memo["Db"] = "C#";
  memo["D#"] = "Eb";
  memo["Eb"] = "D#";
  memo["F#"] = "Gb";
  memo["Gb"] = "F#";
  memo["G#"] = "Ab";
  memo["Ab"] = "G#";
  string note, tonality;
  int t = 1;
  while (cin >> note >> tonality) {
    cout << "Case " << t++ << ": ";
    if (memo.count(note)) {
      cout << memo[note] << " " << tonality << endl;
    } else {
      cout << "UNIQUE" << endl;
    }
  }
  return 0;
}
