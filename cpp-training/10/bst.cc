#include <iostream>
#include <queue>

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
        delete left;
        left = new Node(x);
      } else {
        left->insert(x);
      }
    } else {
      if (right->val == -1) {
        delete right;
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
};

int main() {
  Node node;
  node = Node(5);
  node.insert(1);
  node.insert(6);
  node.insert(3);
  node = Node(6);
  node.print();
}