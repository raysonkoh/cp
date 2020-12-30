#include <iostream>
#include <vector>

using namespace std;

class NChooseK {
public:
  vector<vector<long long>> binomTable;
  NChooseK(int nMax, int kMax) {
    binomTable.assign(nMax + 1, vector<long long>(kMax + 1));
    initBinomTable();
  }
  void initBinomTable() {
    for (long long i = 0; i < binomTable.size(); i++) {
      for (long long j = 0; j < binomTable[i].size(); j++) {
        if (j == 0) {
          binomTable[i][j] = 1;
        } else if (i == 0) {
          binomTable[i][j] = 0;
        } else if (j == 1) {
          binomTable[i][j] = i;
        } else {
          binomTable[i][j] = binomTable[i - 1][j] + binomTable[i - 1][j - 1];
        }
      }
    }
  }
  long long query(int n, int k) { return binomTable[n][k]; }
};

int main() {
  NChooseK nChooseK(1e5, 1e3);
  cout << nChooseK.query(5, 2) << endl;  // 10
  cout << nChooseK.query(3, 2) << endl;  // 3
  cout << nChooseK.query(10, 1) << endl; // 10
  cout << nChooseK.query(0, 1) << endl;  // 0
  cout << nChooseK.query(2, 0) << endl;  // 1
}
