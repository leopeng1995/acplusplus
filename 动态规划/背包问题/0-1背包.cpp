// 输入
int n, W;
int w[MAX_N], v[MAX_N];

// 穷搜法：搜索深度是n，每一层的搜索都需要两个分支，最坏就需要O(2^n)的时间
// 从第i个物品开始挑选总重小于j的部分
int rec(int i, int j) {
	int res;
	if (i == n) {
		// 已经没有剩余物品了
		res = 0;
	} else if (j < w[i]) {
		// 无法挑选这个物品
		res = rec(i + 1, j);
	} else {
		// 挑选和不挑选的两种情况都尝试一下
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return res;
}

void solve() {
	printf("%d\n", rec(0, W));
}

// 记忆化搜索，O(nW)
int dp[MAX_N + 1][MAX_N + 1];	// 记忆化数组

int rec(int i, int j) {
	if (dp[i][j] >= 0) {
		// 已经计算过的话直接使用之前的结果
		return dp[i][j];
	}
	int res;
	if (i == n) {
		res = 0;
	} else if (j < w[i]) {
		res = rec(i + 1, j);
	} else {
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	// 将结果记录在数组中
	return dp[i][j] = res;
}

void solve() {
	// 用-1表示尚未计算过，初始化整个数组
	memset(dp, -1, sizeof(dp));	// 使用memset可以快速地对高维数组等进行初始化
	printf("%d\n", rec(0, W));
}

// 动态规划，O(nW)
int dp[MAX_N + 1][MAX_N + 1];	// DP数组

void solve() {
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j <= W; ++j) {
			if (j < w[i]) {
				dp[i][j] = dp[i + 1][j];
			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}
}

// 动态规划，时间复杂度O(nW)，空间复杂度O(V) (V指的是容积)
int dp[MAX_N + 1];

void solve() {
	for (int i = 0; i < n; ++i) {
		for (int j = W; j >= v[j]; --j) {
			dp[j] = max(dp[j], dp[j - c[j]] + w[j]);
		}
	}
}