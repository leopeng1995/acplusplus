int n, k;
int rank[MAX_N + 1];
int tmp[MAX_N + 1];

// 比较(rank[i], rank[i + k])和(rank[j], rank[j + k])
bool compare_sa(int i, int j) {
	if (rank[i] != rank[j]) return rank[i] < rank[j];
	else {
		int ri = i + k <= n ? rank[i + k] : -1;
		int rj = j + k <= n ? rank[j + k] : -1;
		return ri < rj;
	}
}

// 计算字符串S的后缀数组
void construct_sa(string S, int *sa) {
	n = S.length();

	// 初始长度为1，rank直接取字符的编码
	for (int i = 0; i <= n; i++) {
		sa[i] = i;
		rank[i] = i < n ? S[i] : -1;
	}

	// 利用对长度为k的排序的结果对长度为2k的排序
	for (k = 1; k <= n; k *= 2) {
		sort(sa, sa + n + 1, compare_sa);

		// 先在tmp中临时存储新计算的rank，再转存回rank中
		tmp[sa[0]] = 0;
		for (int i = 1; i <= n; i++) {
			tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
		}
		for (int i = 0; i <= n; i++) {
			rank[i] = tmp[i];
		}
	}
}

bool contain(string S, int *sa, string T) {
	int a = 0, b = S.length();
	while (b - a > 1) {
		int c = (a + b) / 2;
		// 比较S从位置sa[c]开始长度为|T|的子串与T
		if (S.compare(sa[c], T.length(), T) < 0) a = c;
		else b = c;
	}
	int comp = S.compare(sa[b], T.length(), T);
	if (comp == 0) return sa[b];
	return -1;
}