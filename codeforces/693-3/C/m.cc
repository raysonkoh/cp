#include <iostream>
#include <vector>

using namespace std;

template <class T> void print(vector<T> &v) {
  for (T x : v) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<long long> scores(n + 1, 0);
    for (int i = 0; i < n; i++) {
      long long val = v[i] + scores[i];
      if (i + v[i] < n) {
        scores[i + v[i]] = max(scores[i + v[i]], val);
      } else {
        scores[n] = max(scores[n], val);
      }
    }
    long long maxVal = 0;
    for (int i = 0; i < n + 1; i++) {
      maxVal = max(maxVal, scores[i]);
    }

    cout << maxVal << "\n";
  }
}