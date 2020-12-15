#include <iostream>

using namespace std;

void print_arr(int arr[], int n) {
  cout << "sizeof: " << sizeof(arr) << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  cout << "sizeof: " << sizeof(arr) << endl;
  print_arr(arr, 5);
  return 0;
}
