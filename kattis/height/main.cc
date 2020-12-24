#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    int caseNum;
    cin >> caseNum;
    vector<int> v(20, -1);
    int res = 0;
    for (int j = 0; j < 20; j++) {
      int x;
      cin >> x;
      int insertIndx = j;
      while (insertIndx > 0 && v[insertIndx - 1] > x) {
        insertIndx--;
      }
      for (int k = j; k > insertIndx; k--) {
        res++;
        v[k] = v[k - 1];
      }
      v[insertIndx] = x;
    }
    // print(v);
    cout << caseNum << " " << res << endl;
  }
}