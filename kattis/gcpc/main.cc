#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool isBetterTeam(long long aScore, long long aPen, long long bScore,
                  long long bPen) {
  return (aScore > bScore) || (aScore == bScore && aPen < bPen);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;

  vector<long long> score(n + 1, 0);
  vector<long long> penalty(n + 1, 0);
  set<int> betterTeams;

  for (int i = 0; i < m; i++) {
    int t;
    long long p;
    cin >> t >> p;
    score[t]++;
    penalty[t] += p;

    if (t == 1) {
      vector<int> toErase;
      for (auto it : betterTeams) {
        if (!isBetterTeam(score[it], penalty[it], score[1], penalty[1])) {
          toErase.push_back(it);
        }
      }
      for (int x : toErase) {
        betterTeams.erase(x);
      }
    } else {
      if (isBetterTeam(score[t], penalty[t], score[1], penalty[1])) {
        // higher rank than team 1
        if (betterTeams.find(t) == betterTeams.end()) {
          betterTeams.insert(t);
        }
      } else {
        // lower rank than team 1
        if (betterTeams.find(t) != betterTeams.end()) {
          betterTeams.erase(t);
        }
      }
    }
    cout << betterTeams.size() + 1 << "\n";
  }
}