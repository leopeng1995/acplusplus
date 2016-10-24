#include <iostream>
#include <string>
using namespace std;

class TrieNode {
private:
  int type; // 0: 不是单词结点，1: 单词结点
  TrieNode* next[26];
public:
  TrieNode() {
    this->type = 0;
    for (int i = 0; i < 26; i++) next[i] = nullptr;
  }
  friend class Trie;
};

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  void insert(string word) {
    TrieNode *p = root;
    for (auto c = word.begin(); c != word.end(); ++c) {
      if (nullptr == p->next[*c - 'a']) {
        p->next[*c - 'a'] = new TrieNode();
        p = p->next[*c - 'a'];
      } else {
        p = p->next[*c - 'a'];
      }
    }
    p->type = 1;
  }

  bool search(string word) {
    TrieNode *p = root;
    for (auto c = word.begin(); c != word.end(); ++c) {
      if (nullptr == p->next[*c - 'a']) {
        return false;
      } else {
        p = p->next[*c - 'a'];
      }
    }
    return (p->type == 1 ? true : false);
  }

  bool startsWith(string prefix) {
    TrieNode *p = root;
    for (auto c = prefix.begin(); c != prefix.end(); ++c) {
      if (nullptr != p->next[*c - 'a']) {
        p = p->next[*c - 'a'];
      } else {
        return false;
      }
    }
    return true;
  }

private:
  TrieNode* root;
};

int main()
{
  Trie trie;
  trie.insert("somestring");
  trie.insert("key");
  cout << (trie.search("key") ? "true" : "false") << endl;
  trie.insert("some");
  cout << (trie.search("some") ? "true" : "false") << endl;
  cout << (trie.startsWith("somk") ? "true" : "false") << endl;
  return 0;
}
