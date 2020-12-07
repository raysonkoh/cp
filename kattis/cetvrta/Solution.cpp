#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  vector<int> vx;
  vector<int> vy;
  map<int, int> mx;
  map<int, int> my;
  int xres = -1;
  int yres = -1;
  for (int i = 0; i < 3; i++) {
    int x, y;
    cin >> x >> y;
    if (mx.find(x) == mx.end()) {
      mx[x] = 1;
    } else {
      mx[x]++;
    }

    if (my.find(y) == my.end()) {
      my[y] = 1;
    } else {
      my[y]++;
    }
    vx.push_back(x);
    vy.push_back(y);
  }
  for (int i = 0; i < vx.size(); i++) {
    if (mx[vx[i]] == 1) {
      xres = vx[i];
    }
  }

  for (int i = 0; i < vy.size(); i++) {
    if (my[vy[i]] == 1) {
      yres = vy[i];
    }
  }

  cout << xres << " " << yres << endl;

  return 0;
}