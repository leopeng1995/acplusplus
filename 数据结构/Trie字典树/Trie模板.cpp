const int MAX_NODE = 400000 + 10;
const int MAX_SIGMA = 26;

struct Trie {
  int ch[MAX_NODE][MAX_SIGMA];
  int val[MAX_NODE];
  int sz;
  Trie() { init(); }
  void init() { sz = 1; mset0(ch[0]); }
  inline int idx(char c) { return c - 'a'; }
  
  int newnode() {
    mset0(ch[sz]);
    val[sz++] = 0;
    return sz - 1;
  }
  // 插入字符串s，附加信息为v。注意v必须非0，因为0代表“本结点不是单词结点”
  void insert(const char *s, int v) {
    int u = 0, n = strlen(s);
    for (int i = 0; i < n; i++){
      int c = idx(s[i]);
      if(!ch[u][c]) ch[u][c] = newnode();
      u = ch[u][c];
    }
    val[u] = v;
  }
  int query(const char *s) {
    int u = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++){
      if (s[i] == '\0') break;
      int c = idx(s[i]);
      if (!ch[u][c]) break;
      u = ch[u][c];
    }
    return val[u];
  }
};