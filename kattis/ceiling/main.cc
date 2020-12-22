#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node() : val(-1), left(NULL), right(NULL) {}
  Node(int x) : val(x), left(new Node()), right(new Node()) {}
  void insert(int x) {
    if (x < val) {
      if (left->val == -1) {
        // delete left;
        left = new Node(x);
      } else {
        left->insert(x);
      }
    } else {
      if (right->val == -1) {
        // delete right;
        right = new Node(x);
      } else {
        right->insert(x);
      }
    }
  }
  void print() {
    queue<Node *> q;
    cout << val << endl;
    q.push(left);
    q.push(right);
    queue<Node *> tmp;
    while (q.size() > 0 || tmp.size() > 0) {
      if (q.size() == 0) {
        cout << endl;
        q = tmp;
        tmp = queue<Node *>();
      }
      Node *top = q.front();
      q.pop();
      if (top != NULL) {
        cout << top->val << " ";
        tmp.push(top->left);
        tmp.push(top->right);
      }
    }
  }
  bool checkEq(Node *other) {
    // cout << "checking val: " << val << endl;
    // cout << "checking other: " << val << endl;
    if (val == -1) {
      return other->val == -1;
    }
    if (other->val == -1) {
      return val == -1;
    }
    return left->checkEq(other->left) && right->checkEq(other->right);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<Node> v;
  Node nd;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      // cout << "x: " << x << endl;
      if (j == 0) {
        nd = Node(x);
      } else {
        nd.insert(x);
      }
    }
    bool isFound = false;
    for (int j = 0; j < v.size(); j++) {
      // cout << "j: " << j << endl;
      if (v[j].checkEq(&nd)) {
        isFound = true;
      }
    }
    if (!isFound) {
      v.push_back(nd);
    }
  }
  cout << v.size() << endl;
}