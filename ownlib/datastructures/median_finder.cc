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
