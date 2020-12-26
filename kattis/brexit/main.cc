#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long c, p, x, l;
  cin >> c >> p >> x >> l;

  vector<vector<long long>> adjList(c, vector<long long>());
  vector<long long> currDegCount = vector<long long>(c, 0);
  vector<long long> initialDegCount = vector<long long>(c, 0);
  set<long long> deleted;

  for (long long i = 0; i < p; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    // cout << "a: " << a << " b: " << b << endl;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
    currDegCount[a]++;
    currDegCount[b]++;
    initialDegCount[a]++;
    initialDegCount[b]++;
  }

  queue<long long> q;
  l--;
  x--;

  q.push(l);
  deleted.insert(l);

  while (q.size() > 0) {
    long long next = q.front();
    q.pop();
    for (long long i = 0; i < adjList[next].size(); i++) {
      long long node = adjList[next][i];
      if (deleted.find(node) == deleted.end()) {
        // has not been deleted yet
        currDegCount[node]--;
        if (currDegCount[node] <= initialDegCount[node] / 2) {
          // cout << "delete " << node << endl;
          q.push(node);
          deleted.insert(node);
        }
      }
    }
  }

  if (deleted.find(x) == deleted.end()) {
    cout << "stay" << endl;
  } else {
    cout << "leave" << endl;
  }
}
