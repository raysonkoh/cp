#include <iostream>

using namespace std;

int main() {
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    int tmp;
    cin >> tmp;
    cout << tmp << " ";
    int n;
    cin >> n;
    long s1 = 0;
    int initial = 1;
    int count = 0;
    while (count < n) {
      s1 += initial;
      initial++;
      count++;
    }
    long s2 = 0;
    initial = 1;
    count = 0;
    while (count < n) {
      if (initial % 2 == 1) {
        s2 += initial;
        count++;
      }
      initial++;
    }
    long s3 = 0;
    initial = 1;
    count = 0;
    while (count < n) {
      if (initial % 2 == 0) {
        s3 += initial;
        count++;
      }
      initial++;
    }
    cout << s1 << " " << s2 << " " << s3 << endl;
  }
  return 0;
}