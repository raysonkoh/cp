#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
  // if odd size, lesser: (S - 1) / 2 and greater: (S + 1) / 2
  // if even size, lesser: S / 2 and greater: S / 2
  // hence, size(greater) >= size(lesser)
  priority_queue<int> smaller;
  priority_queue<int, vector<int>, greater<int>> bigger;
  int tolSize;
  MedianFinder() : tolSize(0) {}
  void reSize() {
    if (tolSize % 2 == 0) {
      while (bigger.size() < tolSize / 2) {
        int next = smaller.top();
        smaller.pop();
        bigger.push(next);
      }
      while (smaller.size() < tolSize / 2) {
        int next = bigger.top();
        bigger.pop();
        smaller.push(next);
      }
    } else {
      while (bigger.size() < (tolSize + 1) / 2) {
        int next = smaller.top();
        smaller.pop();
        bigger.push(next);
      }
      while (smaller.size() < (tolSize - 1) / 2) {
        int next = bigger.top();
        bigger.pop();
        smaller.push(next);
      }
    }
    while (smaller.size() > 0 && bigger.size() > 0 &&
           smaller.top() > bigger.top()) {
      bigger.push(smaller.top());
      smaller.pop();
      smaller.push(bigger.top());
      bigger.pop();
    }
  }
  void add(int x) {
    bigger.push(x);
    tolSize++;
    reSize();
  }
  int getMedian() {
    tolSize--;
    int res = bigger.top();
    bigger.pop();
    reSize();
    return res;
  }
};

/*
class Brute {
public:
  vector<int> v;
  Brute() {}
  void add(int x) {
    v.push_back(x);
    sort(v.begin(), v.end());
  }
  int getMedian() {
    int res;
    if (v.size() % 2 == 0) {
      res = v[v.size() / 2];
      v.erase(v.begin() + ((v.size() / 2)));
    } else {
      res = v[(v.size() - 1) / 2];
      v.erase(v.begin() + ((v.size() - 1) / 2));
    }
    return res;
  }
};
*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  MedianFinder medianFinder;
  /*
  Brute brute;
  int tolCt = 0;
  for (int j = 0; j < 100000; j++) {
    int x = rand() % 2;
    cout << "j: " << j << " x: " << x << " size: " << tolCt << endl;
    if (x == 1 && tolCt > 0) {
      tolCt--;
      int expect = brute.getMedian();
      int actual = medianFinder.getMedian();
      cout << "get median: E: " << expect << " A: " << actual << endl;
      if (actual != expect) {
        cout << "ERR" << endl;
        break;
      }
    } else {
      tolCt++;
      // int i = rand() % 300000001;
      int i = rand() % 10;
      cout << "add " << i << endl;
      medianFinder.add(i);
      brute.add(i);
    }
  }
  */
  while (cin >> s) {
    if (s == "#") {
      cout << medianFinder.getMedian() << "\n";
    } else {
      int x = stoi(s);
      medianFinder.add(x);
    }
  }
}
