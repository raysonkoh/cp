#include <iostream>
#include <map>
#include <vector>

using namespace std;

class TrieNode {
public:
  int size;
  char c;
  vector<TrieNode *> v;
  TrieNode(char ch) : size(0), c(ch) { v.assign(255, NULL); }
  void insert(string s) {
    size++;
    if (s.length() == 0)
      return;
    char ch = s.at(0);
    int ascii = (int)ch;
    if (v[ascii] == NULL) {
      v[ascii] = new TrieNode(ch);
    }
    v[ascii]->insert(s.substr(1, s.length() - 1));
  }
  int getPrefixSize(string s) {
    // cout << c << endl;
    if (s.length() == 0)
      return size;
    char ch = s.at(0);
    int ascii = (int)ch;
    if (v[ascii] == NULL) {
      return 0;
    }
    return v[ascii]->getPrefixSize(s.substr(1, s.length() - 1));
  }
};

class Trie {
public:
  int size;
  vector<TrieNode *> v;
  Trie() : size(0) { v.assign(255, NULL); }
  void insert(string s) {
    size++;
    if (s.length() == 0)
      return;
    char ch = s.at(0);
    int ascii = (int)ch;
    if (v[ascii] == NULL) {
      v[ascii] = new TrieNode(ch);
    }
    v[ascii]->insert(s.substr(1, s.length() - 1));
  }
  int getPrefixSize(string s) {
    if (s.length() == 0)
      return size;
    char ch = s.at(0);
    int ascii = (int)ch;
    if (v[ascii] == NULL) {
      return 0;
    }
    return v[ascii]->getPrefixSize(s.substr(1, s.length() - 1));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  Trie trie;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cout << trie.getPrefixSize(s) << endl;
    trie.insert(s);
  }
}