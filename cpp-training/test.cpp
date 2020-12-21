#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int> pq;
  pq.push(4);
  pq.push(4);
  cout << pq.top() << endl;
  pq.pop();
  cout << pq.top() << endl;
  cout << (nullptr == nullptr) << endl;

  return 0;
}
