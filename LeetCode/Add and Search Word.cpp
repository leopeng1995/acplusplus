// 树的层次遍历 + Trie
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class TrieNode {
private:
  int type; // 0: 不是单词结点，1: 单词结点
  int num;
  TrieNode* next[26];
public:
  TrieNode() {
    this->type = 0;
    this->num = 1;
    for (int i = 0; i < 26; i++) next[i] = nullptr;
  }
  friend class WordDictionary;
};

class WordDictionary {
public:
  WordDictionary() {
    root = new TrieNode();
  }
public:
  void addWord(string word) {
    TrieNode *p = root;
    for (auto c = word.begin(); c != word.end(); ++c) {
      if (nullptr == p->next[*c - 'a']) {
        p->next[*c - 'a'] = new TrieNode();
        p = p->next[*c - 'a'];
      } else {
        p = p->next[*c - 'a'];
        p->num++;
      }
    }
    p->type = 1;
  }

  bool search(string word) {
    queue<TrieNode*> q;

    TrieNode *p = root;
    q.push(p);

    for (auto c = word.begin(); c != word.end(); ++c) {
      int size = q.size();
      while (size--) {
        TrieNode *u = q.front();
        q.pop();

        if (*c == '.') {
          for (int i = 0; i < 26; ++i) {
            if (nullptr != u->next[i]) {
              q.push(u->next[i]);
            }
          }
        } else {
          if (nullptr != u->next[*c - 'a' ]) {
            q.push(u->next[*c - 'a' ]);
          }
        }
      }
      if (0 == q.size()) return false;
    }
    while (!q.empty()) {
      TrieNode *u = q.front();
      q.pop();
      if (u->type == 1) return true;
    }
    return false;
  }
private:
  TrieNode* root;
};

int main()
{
  WordDictionary wordDictionary;
  wordDictionary.addWord("bad");
  wordDictionary.addWord("dad");
  wordDictionary.addWord("mad");
  cout << wordDictionary.search("pad") << endl;
  cout << wordDictionary.search("bad") << endl;
  cout << wordDictionary.search(".ad") << endl;
  cout << wordDictionary.search("b..") << endl;
  return 0;
}
