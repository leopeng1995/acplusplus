// tree[p][i] 第p层中第i位置的整数值，初始序列为tree[0][]
// sorted[] 排序序列，即存储tree[0][]排序后的结果
// toleft[][] toleft[p][i]表示第p层前i个数里有多少个整数分入下一层的左子区间
// lpos和rpos 下一层左子区间和右子区间
// same 当前区间等于中间值的整数个数
void build(int l, int r, int dep)
{
	if(l == r) return;
	int mid = (l+r)>>1;
	int same = mid - l + 1;
	
}