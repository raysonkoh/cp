#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<int> start(n, 0);
  vector<pair<int, int>> end(n);
  vector<int> assign(n, 0);
  vector<int> serverLoad(n, 0);
  stack<int> s;

  for (int i = 0; i < n; i++) {
    int ti;
    cin >> ti;
    start[i] = ti;
    end[i] = make_pair(i, ti + 1000);
  }
  int startIndx = 0;
  int endIndx = 0;
  int maxServerNum = 0;

  while (startIndx < start.size() && endIndx < end.size()) {
    if (start[startIndx] < end[endIndx].second) {
      // process start
      int processNum = startIndx;
      int time = start[startIndx];
      // cout << "process start, num: " << processNum << " time: " << time <<
      // endl;
      if (s.size() == 0) {
        s.push(maxServerNum);
        // cout << "add new server: " << maxServerNum << endl;
        maxServerNum++;
      }
      int serverNum = s.top();
      assign[processNum] = serverNum;
      serverLoad[serverNum]++;
      if (serverLoad[serverNum] == k) {
        s.pop();
      }
      startIndx++;
    } else {
      // process end
      pair<int, int> p = end[endIndx];
      int processNum = p.first;
      int time = p.second;
      // cout << "process end, num: " << processNum << " time: " << time <<
      // endl;
      int assignedServer = assign[processNum];
      serverLoad[assignedServer]--;
      if (serverLoad[assignedServer] == k - 1) {
        // cout << "server becomes available: " << assignedServer << endl;
        s.push(assignedServer);
      }
      endIndx++;
    }
  }
  cout << maxServerNum << endl;
}