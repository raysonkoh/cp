#include <iostream>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    stack<int> s;             // 0
    queue<int> q;             // 1
    priority_queue<int> maxH; // 2
    set<int> se;
    se.insert(0);
    se.insert(1);
    se.insert(2);
    for (int i = 0; i < n; i++) {
      int t, x;
      cin >> t >> x;
      if (t == 1) {
        // add
        for (int i = 0; i < 4; i++) {
          if (se.find(i) != se.end()) {
            if (i == 0) {
              s.push(x);
            } else if (i == 1) {
              q.push(x);
            } else if (i == 2) {
              maxH.push(x);
            }
          }
        }
      } else {
        // remove
        for (int i = 0; i < 4; i++) {
          if (se.find(i) != se.end()) {
            int fr;
            if (i == 0) {
              if (s.size() == 0) {
                fr = -1;
              } else {
                fr = s.top();
                s.pop();
              }
            } else if (i == 1) {
              if (q.size() == 0) {
                fr = -1;
              } else {
                fr = q.front();
                q.pop();
              }
            } else if (i == 2) {
              if (maxH.size() == 0) {
                fr = -1;
              } else {
                fr = maxH.top();
                maxH.pop();
              }
            }

            if (fr != x) {
              // cout << "fr: " << fr << " x: " << x << " i: " << i << endl;
              se.erase(i);
            }
          }
        }
      }
    }
    // cout << "size: " << se.size() << endl;
    if (se.size() == 1) {
      for (int i = 0; i < 4; i++) {
        if (se.find(i) != se.end()) {
          if (i == 0) {
            cout << "stack" << endl;
          } else if (i == 1) {
            cout << "queue" << endl;
          } else if (i == 2) {
            cout << "priority queue" << endl;
          }
        }
      }
    } else if (se.size() > 1) {
      cout << "not sure" << endl;
    } else {
      cout << "impossible" << endl;
    }
  }
  return 0;
}