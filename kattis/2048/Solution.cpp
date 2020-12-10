#include <iostream>
#include <set>
#include <vector>

using namespace std;

void print(vector<vector<int>> &m) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      // cout << "i: " << i << " j: " << j << endl;
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

vector<vector<int>> leftrotate(vector<vector<int>> &m) {
  vector<vector<int>> res;
  for (int j = 3; j >= 0; j--) {
    vector<int> tmp;
    for (int i = 0; i < 4; i++) {
      int curr = m[i][j];
      tmp.push_back(curr);
    }
    res.push_back(tmp);
  }
  return res;
}

vector<vector<int>> moveleft(vector<vector<int>> &m) {
  vector<vector<int>> res;
  for (int i = 0; i < 4; i++) {
    vector<int> tmp;
    set<pair<int, int>> merged;
    int numEle = 0;
    for (int j = 0; j < 4; j++) {
      // cout << "i: " << i << " j: " << j << endl;
      // find first non-zero
      int val = m[i][j];
      if (val == 0) {
        // cout << "0, continue" << endl;
        continue;
      }
      if (numEle == 0) {
        // cout << "pushing " << val << endl;
        tmp.push_back(val);
        numEle++;
      } else if (tmp[numEle - 1] == val &&
                 merged.find(make_pair(i, numEle - 1)) == merged.end()) {
        // cout << "merge " << 2 * val << endl;
        tmp[numEle - 1] = 2 * val;
        merged.insert(make_pair(i, numEle - 1));
      } else {
        tmp.push_back(val);
        numEle++;
      }
    }
    while (tmp.size() < 4) {
      tmp.push_back(0);
    }
    // for (int i = 0; i < 4; i++) {
    //  cout << tmp[i] << " ";
    //}
    // cout << endl;
    res.push_back(tmp);
  }
  return res;
}

int main() {
  vector<vector<int>> m;
  for (int i = 0; i < 4; i++) {
    vector<int> tmp;
    for (int j = 0; j < 4; j++) {
      int val;
      cin >> val;
      tmp.push_back(val);
    }
    m.push_back(tmp);
  }

  // vector<vector<int>> tmp = leftrotate(m);
  // tmp = leftrotate(tmp);
  // tmp = leftrotate(tmp);
  // vector<vector<int>> tmp = moveleft(m);
  // print(tmp);

  int dir;
  cin >> dir;
  vector<vector<int>> tmp = m;
  if (dir == 0) {
    // left
    tmp = moveleft(tmp);
  } else if (dir == 1) {
    // up
    tmp = leftrotate(tmp);
    tmp = moveleft(tmp);
    for (int i = 0; i < 3; i++) {
      tmp = leftrotate(tmp);
    }
  } else if (dir == 2) {
    // right
    for (int i = 0; i < 2; i++) {
      tmp = leftrotate(tmp);
    }
    tmp = moveleft(tmp);
    for (int i = 0; i < 2; i++) {
      tmp = leftrotate(tmp);
    }
  } else if (dir == 3) {
    // down
    for (int i = 0; i < 3; i++) {
      tmp = leftrotate(tmp);
    }
    tmp = moveleft(tmp);
    tmp = leftrotate(tmp);
  }
  print(tmp);

  return 0;
}
