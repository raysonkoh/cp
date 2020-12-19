#include <iostream>

using namespace std;

int parseyear(string datestr) {
  string res = datestr.substr(0, 4);
  return stoi(res);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name, postsec, dob;
    int courses;
    cin >> name >> postsec >> dob >> courses;
    int postsecyr = parseyear(postsec);
    int dobyr = parseyear(dob);

    int sems = courses / 5;
    if (courses % 5 != 0) {
      sems++;
    }

    cout << name << " ";
    if (postsecyr >= 2010 || dobyr >= 1991) {
      cout << "eligible" << endl;
    } else if (sems > 8) {
      cout << "ineligible" << endl;
    } else {
      cout << "coach petitions" << endl;
    }
  }
}