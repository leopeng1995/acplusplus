#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define sc3(n,m,t) scanf("%d%d%d",&n,&m,&t)
#define mset0(arr) memset(arr, 0, sizeof(arr))
#define L(x) (1 << (x))
#define INF 0xffffff
#define lowbit(x) x&(-x)

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d ", array[i])
#define DEBUG_PRINT_MATRIX(matrix) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }
#define DEBUG_PRINT_MATRIX2(matrix, n, m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long int64;	// %lld

class LRUCache {
private:
	struct CacheNode {
		int key;
		int value;
		CacheNode(int k, int v) : key(k), value(v) {}
	};

private:
	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap;
	int capacity;

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (cacheMap.find(key) == cacheMap.end()) return -1;

		// 把当前访问的节点移到链表头部，并且更新map中该节点的地址
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}

	void set(int key, int value) {
		if (cacheMap.find(key) == cacheMap.end()) {
			if (cacheList.size() == capacity) {	// 删除链表尾部节点（最少访问节点）
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			// 插入新节点
			cacheList.push_front(CacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		} else {
			// 更新节点的值，把当前访问的节点移到链表头部，并且更新 map 中该节点的地址
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
};

int main()
{
  freopen("in.txt", "r", stdin);
  int n, k;
  int key, value;
  char cmd[4];
  while (sc(n) != EOF && n != -1) {
    sc(k);
    LRUCache cache = LRUCache(n);
    for (int i = 0; i < k; i++) {
      scanf("%s", cmd);
      if (strcmp(cmd, "SET") == 0) {
        sc2(key, value);
        cache.set(key, value);
      } else {
        sc(key);
        int status = cache.get(key);
        printf(status == -1 ? "null\n" : "%d\n", status);
      }
    }
  }
  return 0;
}
