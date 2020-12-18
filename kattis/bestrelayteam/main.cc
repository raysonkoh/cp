#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<pair<double, string>> va;
  vector<pair<double, string>> vb;
  vector<string> lineup;
  double best = 100.0;

  for (int i = 0; i < n; i++) {
    string name;
    double a, b;
    cin >> name >> a >> b;
    va.push_back(make_pair(a, name));
    vb.push_back(make_pair(b, name));
  }
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());

  for (int i = 0; i < 4; i++) {
    pair<double, string> first = va[i];
    for (int j = 0; j < 4; j++) {
      pair<double, string> second = vb[j];
      if (second.second == first.second) {
        continue;
      }
      for (int k = 0; k < 4; k++) {
        pair<double, string> third = vb[k];
        if (third.second == second.second || third.second == first.second) {
          continue;
        }
        for (int l = 0; l < 4; l++) {
          pair<double, string> fourth = vb[l];
          if (fourth.second == third.second || fourth.second == second.second ||
              fourth.second == first.second) {
            continue;
          }
          double currbest =
              first.first + second.first + third.first + fourth.first;
          if (currbest < best) {
            best = currbest;
            lineup.clear();
            lineup.push_back(first.second);
            lineup.push_back(second.second);
            lineup.push_back(third.second);
            lineup.push_back(fourth.second);
          }
        }
      }
    }
  }
  cout << best << endl;
  for (int i = 0; i < 4; i++) {
    cout << lineup[i] << endl;
  }
}
