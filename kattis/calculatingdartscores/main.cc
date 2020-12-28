#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

void print(int a, int b) {
  if (b == 0) {
    return;
  }
  if (b == 3) {
    cout << "triple " << a << endl;
  } else if (b == 2) {
    cout << "double " << a << endl;
  } else {
    cout << "single " << a << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x;
  cin >> x;
  map<int, tuple<int, int>> first;
  for (int i = 1; i <= 20; i++) {
    first[i] = make_tuple(i, 1);
    first[i * 2] = make_tuple(i, 2);
    first[i * 3] = make_tuple(i, 3);
  }
  map<int, tuple<int, int, int, int>> second;
  for (int i = 1; i <= 20; i++) {
    for (auto j : first) {
      int a = get<0>(j.second);
      int b = get<1>(j.second);
      int pS = j.first;
      second[pS] = make_tuple(a, b, i, 0);
      second[pS + i] = make_tuple(a, b, i, 1);
      second[pS + 2 * i] = make_tuple(a, b, i, 2);
      second[pS + 3 * i] = make_tuple(a, b, i, 3);
    }
  }
  map<int, tuple<int, int, int, int, int, int>> third;
  for (int i = 1; i <= 20; i++) {
    for (auto j : second) {
      int a = get<0>(j.second);
      int b = get<1>(j.second);
      int c = get<2>(j.second);
      int d = get<3>(j.second);
      int pS = j.first;
      third[pS] = make_tuple(a, b, c, d, i, 0);
      third[pS + i] = make_tuple(a, b, c, d, i, 1);
      third[pS + 2 * i] = make_tuple(a, b, c, d, i, 2);
      third[pS + 3 * i] = make_tuple(a, b, c, d, i, 3);
    }
  }

  if (third.find(x) == third.end()) {
    cout << "impossible" << endl;
  } else {
    tuple<int, int, int, int, int, int> t = third.find(x)->second;
    int a = get<0>(t);
    int b = get<1>(t);
    print(a, b);
    int c = get<2>(t);
    int d = get<3>(t);
    print(c, d);
    int e = get<4>(t);
    int f = get<5>(t);
    print(e, f);
  }
}