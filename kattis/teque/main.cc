#include <deque>
#include <iostream>

using namespace std;

class Teque {
public:
  deque<int> front;
  deque<int> back;

  Teque() : front(deque<int>()), back(deque<int>()) {}

  void resize() {
    int tolsize = front.size() + back.size();

    int midsize = tolsize / 2;
    if (tolsize % 2 == 0) {
      while (front.size() > back.size()) {
        int tmp = front.back();
        front.pop_back();
        back.push_front(tmp);
      }
      while (back.size() > front.size()) {
        int tmp = back.front();
        back.pop_front();
        front.push_back(tmp);
      }
    } else {
      // front: mid + 1, back: mid
      while (front.size() > midsize + 1) {
        int tmp = front.back();
        front.pop_back();
        back.push_front(tmp);
      }
      while (back.size() > midsize) {
        int tmp = back.front();
        back.pop_front();
        front.push_back(tmp);
      }
    }
  }

  void print() {
    for (int i = 0; i < front.size(); i++) {
      cout << front.at(i) << " ";
    }
    for (int i = 0; i < back.size(); i++) {
      cout << back.at(i) << " ";
    }
    cout << endl;
  }

  void push_front(int x) {
    front.push_front(x);
    resize();
  }

  void push_back(int x) {
    back.push_back(x);
    resize();
  }

  void push_middle(int x) {
    back.push_front(x);
    resize();
  }

  int get(int i) {
    if (i < front.size()) {
      return front.at(i);
    } else {
      i = i - front.size();
      return back.at(i);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  Teque t;
  for (int i = 0; i < n; i++) {
    string cmd;
    int x;
    cin >> cmd >> x;
    if (cmd == "push_front") {
      t.push_front(x);
    } else if (cmd == "push_back") {
      t.push_back(x);
    } else if (cmd == "push_middle") {
      t.push_middle(x);
    } else {
      cout << t.get(x) << endl;
    }
    // cout << cmd << " " << x << " : ";
    // t.print();
  }
}
