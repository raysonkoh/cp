#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node(int x) : val(x), left(&Node()), right(&Node()) {}
  Node() : val(-1), left(nullptr), right(nullptr) {}
  void insert(int x) {
    if (x < val) {
      if (left == nullptr) {
        Node newLeft(x);
        left = &newLeft;
      } else {
        left->insert(x);
      }
    } else {
      if (right == nullptr) {
        Node newRight(x);
        right = &newRight;
      } else {
        right->insert(x);
      }
    }
  }
  bool checkEq(Node *other) { if (val == -1) }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<Node *> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
    }
  }
}