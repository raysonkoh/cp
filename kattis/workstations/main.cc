#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pair<long long, int>> start(n); // (starttime, label)
  vector<pair<long long, int>> end(n);   // (endtime, label)
  vector<int> assign(n);
  for (int i = 0; i < n; i++) {
    long long a, s;
    cin >> a >> s;
    start[i] = make_pair(a, i);
    end[i] = make_pair(a + s, i);
  }
  sort(start.begin(), start.end());
  sort(end.begin(), end.end());
  int startIndx = 0;
  int endIndx = 0;
  queue<int> locked;
  queue<pair<long long, int>> unlocked; // (lastused, label)
  int maxWorkNum = 0;
  int res = 0;
  while (startIndx < start.size() && endIndx < end.size()) {
    if (start[startIndx].first < end[endIndx].first) {
      // process start
      long long startTime = start[startIndx].first;
      int label = start[startIndx].second;

      if (unlocked.size() == 0) {
        // cout << "no unlocked for " << label << ", startTime: " << startTime
        //     << endl;
        if (locked.size() == 0) {
          assign[label] = maxWorkNum;
          maxWorkNum++;
        } else {
          int workNum = locked.front();
          locked.pop();
          assign[label] = workNum;
        }
      } else {
        bool hasAssigned = false;
        while (unlocked.size() > 0) {
          pair<long long, int> p = unlocked.front();
          unlocked.pop();
          if (startTime <= p.first + m) {
            // cout << "assigned label " << label << ", startTime: " <<
            // startTime
            //     << " to " << p.second << endl;
            // cout << p.first << endl;
            hasAssigned = true;
            assign[label] = p.second;
            res++;
            break;
          } else {
            locked.push(p.second);
          }
        }
        if (!hasAssigned) {
          // cout << "no assigned for " << label << ", startTime: " << startTime
          //     << endl;
          if (locked.size() == 0) {
            assign[label] = maxWorkNum;
            maxWorkNum++;
          } else {
            int workNum = locked.front();
            locked.pop();
            assign[label] = workNum;
          }
        }
      }
      startIndx++;
    } else {
      // process end
      long long endTime = end[endIndx].first;
      int label = end[endIndx].second;
      int workstationNum = assign[label];
      unlocked.push(make_pair(endTime, workstationNum));
      endIndx++;
    }
  }
  cout << res << endl;
}