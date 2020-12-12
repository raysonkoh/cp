#include <iostream>
#include <vector>

using namespace std;

int main() {
  // 2009
  // 1 - Thurs
  // 2 - sun
  // 3 - sun
  // 4 - wed
  // 5 - fri
  // 6 - mon
  // 7 - wed
  // 8 - sat
  // 9 - tues
  // 10 - thurs
  // 11 - sun
  // 12 - tues
  vector<int> v;
  v.push_back(4);
  v.push_back(7);
  v.push_back(7);
  v.push_back(3);

  v.push_back(5);
  v.push_back(1);
  v.push_back(3);
  v.push_back(6);

  v.push_back(2);
  v.push_back(4);
  v.push_back(7);
  v.push_back(2);

  int d, m;
  cin >> d >> m;
  int day = v[m - 1];
  int tmp = 1;
  while (tmp < d) {
    day++;
    if (day > 7) {
      day = 1;
    }
    tmp++;
  }
  if (day == 1) {
    cout << "Monday" << endl;
  } else if (day == 2) {
    cout << "Tuesday" << endl;
  } else if (day == 3) {
    cout << "Wednesday" << endl;
  } else if (day == 4) {
    cout << "Thursday" << endl;
  } else if (day == 5) {
    cout << "Friday" << endl;
  } else if (day == 6) {
    cout << "Saturday" << endl;
  } else if (day == 7) {
    cout << "Sunday" << endl;
  }
  cin >> d >> m;
  return 0;
}
