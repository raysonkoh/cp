#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  map<int, vector<int>> adjList;
  for (int i = 0; i < n; i++) {
    vector<int> tmp;
    adjList[i] = tmp;
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  // bfs from 0, find connected nodes => complement to find unconnected nodes
  queue<int> q;
  set<int> seen;
  q.push(0);
  seen.insert(0);

  while (q.size() > 0) {
    int next = q.front();
    q.pop();

    vector<int> neis = adjList[next];
    for (int i = 0; i < neis.size(); i++) {
      int nei = neis[i];
      if (seen.find(nei) == seen.end()) {
        seen.insert(nei);
        q.push(nei);
      }
    }
  }

  if (seen.size() == n) {
    cout << "Connected" << endl;
  } else {
    for (int i = 0; i < n; i++) {
      if (seen.find(i) == seen.end()) {
        cout << i + 1 << endl;
      }
    }
  }

  return 0;
}
