#include <iostream>
#include <vector>
#include <string>
#include <set>

#define USE_CPLUSPLUS0x 1

#if USE_CPLUSPLUS0x
  #include <unordered_map>
#else
  #include <map>
#endif

#include <cassert>

using std::string;
using std::vector;
using std::cout;

/*      //----
#if USE_CPLUSPLUS0x
  struct Cmp{
    bool operator()(const string* a, const string* b) const { return *a == *b; }
  } ;

  struct Hash{
    size_t operator()(const string* a) const { return std::hash<string>()(*a);}
  } ;

  typedef std::unordered_map<const string*, size_t, Hash, Cmp> Dict;
#else
  struct Cmp{
    bool operator()(const string* sa, const string * sb) const { return *sa < *sb; }
  } ;

  typedef std::map<const string*, size_t, Cmp> Dict;
#endif
 */

#if USE_CPLUSPLUS0x
  typedef std::unordered_map<string, size_t> Dict;
#else
  typedef std::map<string, size_t> Dict;
#endif

template<typename T>
void output(T beg, T end, const char str[] = "", const char sep[] = "")
{
  cout << str;
  while (beg != end) cout << *beg++ << sep;
  cout << "\n";
}

void solve(const string str[], const size_t str_sz,
           const string keyword[], const size_t keyword_sz)
{
  if (str_sz == 0 || keyword_sz == 0) return;

  Dict key_idx; // 关键字映射为数字，以减少字符串比较
  for (size_t i = 0; i < keyword_sz; ++i) {
    // key_idx.insert(Dict::value_type(&keyword[i], i)); //----
    key_idx.insert(Dict::value_type(keyword[i], i));
  }
  const size_t Pos_init = -1;
  vector<size_t> prev_pos(keyword_sz, Pos_init);  // 上次碰到的关键字符串的位置
  std::set<size_t> pos; // 对关键字符串的位置进行升序排列

  vector<size_t> old_pos; // 分词后的字符串，在原字符串中的位置
  old_pos.reserve(str_sz + 1);
  old_pos.push_back(0);
  for (size_t i = 0, sum = 0; i < str_sz; ++i) {
    sum += str[i].size();
    old_pos.push_back(sum);
  }

  size_t beg = 0, end = 0, len = -1, count = 0; // 记录结果
  for (size_t i = 0; i < str_sz; ++i) {
    // Dict::iterator it = key_idx.find(&str[i]); //----
    Dict::iterator it = key_idx.find(str[i]);

    if (it == key_idx.end()) continue;

    assert(it->second < prev_pos.size());
    size_t& last_pos = prev_pos[it->second];
    if (last_pos != Pos_init)  pos.erase(last_pos); // 更新前要先删除旧的
    else ++count; // 已匹配关键字 数加1
    last_pos = i;

    pos.insert(pos.end(), i);

    assert(count <= keyword_sz);
    if (count == keyword_sz) {  // 包含所有关键字
      size_t pbeg = *pos.begin();
      // std::set<size_t>::iterator it = pos.end();
      // size_t pend = *--it + 1;
      size_t pend = i + 1;

      assert(pbeg < old_pos.size());
      assert(pend < old_pos.size());

      size_t plen =  old_pos[pend] - old_pos[pbeg];
      if (plen < len) {
        len = plen;
        beg = pbeg;
        end = pend;
      }
    }
  }

  output(&str[0], &str[str_sz], "words:    ");
  output(&keyword[0], &keyword[keyword_sz], "keywords: ", " ");

  if (beg == end && !pos.empty()) {      //没找到所有关键字
    cout << "(" << pos.size() << "/" << keyword_sz << " Matched) ";
    beg = *pos.begin();
    std::set<size_t>::iterator it = pos.end();
    end = *--it + 1;
  }
  output(&str[beg], &str[end], "result:   ");
  cout << "\n";
}

template<typename T, size_t sz>
inline size_t getsz(T (&)[sz]) { return sz; }

int main()
{
  string keyword[] = { "微软", "计算机", "亚洲"};
  // string keyword[] = { "微软", "计算机", "亚洲", "中国"};
  string str[] = {
    "微软","亚洲","研究院","成立","于","1998","年","，","我们","的","使命",
    "是","使","未来","的","计算机","能够","看","、","听","、","学","，",
    "能","用","自然语言","与","人类","进行","交流","。","在","此","基础","上",
    "，","微软","亚洲","研究院","还","将","促进","计算机","在","亚太","地区",
    "的","普及","，","改善","亚太","用户","的","计算","体验","。","”"
  };

  solve(str, getsz(str), keyword, getsz(keyword));
}
