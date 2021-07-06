#include <vector>

using namespace std;

// [N1xM1] * [M1xN2] = [N1xN2]
vector<vector<long long>> mult(vector<vector<long long>> v1, vector<vector<long long>> v2) {
  int n1 = v1.size(), m1 = v1[0].size(), n2 = v2[0].size();
  vector<vector<long long>> res(n1, vector<long long>(n2));
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      // ith row of v1 * jth col of v2
      res[i][j] = 0;
      for (int k = 0; k < m1; k++) {
        // res[i][j] = (res[i][j] + (v1[i][k] * v2[k][j]) % P) % P;
        res[i][j] += v1[i][k] * v2[k][j];
      }
    }
  }
  return res;
}

vector<vector<long long>> fastMatPow(vector<vector<long long>> v, long long n) {
  if (n == 0) {
    // identity matrix
    vector<vector<long long>> res(v.size(), vector<long long>(v.size(), 0));
    for (int i = 0; i < v.size(); i++)
      res[i][i] = 1;
    return res;
  }

  if (n == 1)
    return v;

  vector<vector<long long>> tmp = fastMatPow(v, n / 2);
  if (n % 2 == 0) {
    return mult(tmp, tmp);
  } else {
    return mult(mult(v, tmp), tmp);
  }
}

int main() {
}
