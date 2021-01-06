#include <cmath>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int p, d;
  cin >> p >> d;
  vector<long long> va(d, 0);
  vector<long long> vb(d, 0);
  long long V = 0;

  while (p--) {
    int di;
    long long a, b;
    cin >> di >> a >> b;
    di--;
    va[di] += a;
    vb[di] += b;
    V += a + b;
  }

  vector<tuple<int, long long, long long>> res(d); // ({0,1} - who wins, losta, lostb)
  for (int i = 0; i < d; i++) {
    int winner = 0; // A wins
    if (vb[i] > va[i])
      winner = 1;

    long long losta = 0;
    long long lostb = 0;
    if (!winner) {
      // A wins
      losta = va[i] - ((va[i] + vb[i]) / 2 + 1);
      lostb = vb[i];
    } else {
      // B wins
      losta = va[i];
      lostb = vb[i] - ((va[i] + vb[i]) / 2 + 1);
    }

    res[i] = {winner, losta, lostb};
  }
  long long la = 0;
  long long lb = 0;
  for (auto [w, losta, lostb] : res) {
    cout << (w == 0 ? 'A' : 'B') << " " << losta << " " << lostb << "\n";
    la += losta;
    lb += lostb;
  }
  double efficiency = ((double)abs(la - lb)) / ((double)V);
  cout << fixed << setprecision(8) << efficiency << '\n';
}