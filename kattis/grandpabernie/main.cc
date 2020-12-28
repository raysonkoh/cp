#include <bits/extc++.h>
#include <iostream>
#include <map>

using namespace std;

using namespace __gnu_pbds;
typedef tree<double, null_type, less<double>, rb_tree_tag,
             tree_order_statistics_node_update>
    ost;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  map<string, ost> m;
  int n;
  cin >> n;
  while (n--) {
    string country;
    int y;
    cin >> country >> y;
    if (m.find(country) == m.end()) {
      ost tree;
      m[country] = tree;
    }
    m[country].insert(y + (((double)n) / ((double)1e5 + 10.0)));
    // cout << "size: " << m[country].size() << endl;
  }

  int q;
  cin >> q;
  while (q--) {
    string country;
    int rank;
    cin >> country >> rank;
    rank--;
    cout << ((int)*m[country].find_by_order(rank)) << "\n";
  }
}