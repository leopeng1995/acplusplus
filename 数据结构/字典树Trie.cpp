// 第一类应用：统计一组字符串中某前缀出现次数
// 第二类应用：判断一组字符串中是否有一个字符串是另一个字符串的前缀

typedef struct TrieNode
{
  int nCount; // 记录该字符出现次数
  int nValue; // 记录附加信息，为0表示“该结点不是单词结点”
  struct TrieNode *next[26];
} TrieNode;

TrieNode Memory[1000000];
int allocp = 0;

/*初始化*/
void Init(TrieNode **pRoot) {
  *pRoot = NULL;
}

/*创建新结点*/
TrieNode *Create()
{
  TrieNode *p;
  p = &Memory[allocp++];
  p->nCount = 1;
  for(int i = 0 ; i < 26; ++i) p->next[i] = NULL;
  return p;
}

/*插入*/
void Insert(TrieNode **pRoot , char *s)
{
  TrieNode *p;
  if(!(p = *pRoot)) p = *pRoot = Create();
  int i = 0, k;
  while(s[i]) {
    k = s[i++] - 'a'; //确定branch
    if(p->next[k]) p->next[k]->nCount++;
    else p->next[k] = Create();
    p = p->next[k];
  }
}

//查找
int Query(TrieNode **pRoot , char *s)
{
  TrieNode *p;
  if(!(p = *pRoot)) return 0;
  int i = 0, k;
  while(s[i]) {
    k = s[i++] - 'a';
    if(p->next[k] == NULL) return 0;
    p = p->next[k];
  }
  return p->nCount;
}