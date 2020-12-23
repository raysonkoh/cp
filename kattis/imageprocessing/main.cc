#include <iostream>
#include <vector>

using namespace std;

int calc(vector<vector<int>> &v, vector<vector<int>> &ker) {
  int res = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      // cout << ker[v[i].size() - 1 - j][v.size() - 1 - i] << endl;
      res += v[i][j] * ker[v[i].size() - 1 - j][v.size() - 1 - i];
    }
  }
  return res;
}

void print2d(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (j == 0) {
        cout << v[i][j];
      } else {
        cout << " " << v[i][j];
      }
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int h, w, n, m;
  cin >> h >> w >> n >> m;
  vector<vector<int>> img(h, vector<int>(w));
  vector<vector<int>> ker(n, vector<int>(m));
  vector<vector<int>> slide(m, vector<int>(n));
  vector<vector<int>> res(h - n + 1, vector<int>(w - m + 1));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int x;
      cin >> x;
      img[i][j] = x;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      ker[i][j] = x;
    }
  }
  for (int i = 0; i < res.size(); i++) {
    // init slide
    for (int a = 0; a < m; a++) {
      for (int b = i; b < i + n; b++) {
        // cout << "img[" << b << "][" << a << "]"
        //     << " to "
        //     << "slide[" << a << "][" << b << "]" << endl;
        slide[a][b - i] = img[b][a];
      }
    }
    res[i][0] = calc(slide, ker);
    // cout << "res[" << i << "]["
    //     << "0]"
    //     << ": " << res[i][0] << endl;
    // cout << "init" << endl;
    // print2d(slide);
    for (int j = 1; j < res[i].size(); j++) {
      slide.erase(slide.begin());
      vector<int> tmp;
      for (int b = i; b < i + n; b++) {
        tmp.push_back(img[b][j + m - 1]);
      }
      slide.push_back(tmp);
      res[i][j] = calc(slide, ker);
      // cout << "res[" << i << "][" << j << "]"
      //     << ": " << res[i][j] << endl;
      // print2d(slide);
    }
  }
  print2d(res);
}
