#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int arr[N];
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    arr[i] = tmp;
  }
  for (int i = N - 1; i >= 0; i--) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}