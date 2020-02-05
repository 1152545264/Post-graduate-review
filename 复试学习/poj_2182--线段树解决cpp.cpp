#include<iostream>
#include <vector>
using namespace  std;

static const int Max = 10000;
static struct
{
	int l, r, len;
}tree[Max<<2];

static int pre[Max], ans[Max];

void Build(int left, int right, int u)  //建立线段树的函数
{
	tree[u].l = left;
	tree[u].r = right;
	tree[u].len = right - left + 1;
	if (left == right )  //递归函数的出口
	{
		return;
	}

	Build(left, (left + right) >> 1, u << 1);  //递归构建左子树
	Build(((left + right) >> 1) + 1, right, (u << 1) + 1); //递归构建右子树
}

int Query(int u, int num)  //线段树的查询+维护函数。所求值为当前区间左起第num个元素
{
	tree[u].len--;  //对访问到的区间维护len：具体做法就是把这个节点牛的数量减少1
	if (tree[u].l == tree[u].r	)
	{
		return tree[u].l;
	}
	//情况1：左子区间内牛的个数不够，则需要查询右子区间中左起第 num - tree[u<<1].len 个元素
	if (tree[u<<1].len	 < num	)
	{
		return Query( (u << 1) + 1, num - tree[u << 1].len);
	}
	if (tree[u<<1].len >= num)    //左子区间内牛的数量足够，则依旧查询左子区间中左起第num个元素
	{
		return Query(u << 1, num);
	}
}

static int main3() 
{
	int n, i;
	cin >> n;
	pre[1] = 0;
	for (i = 2; i <= n; ++i)
	{
		cin >> pre[i];
	}
	Build(1, n, 1);
	for (i = n; i >= 1; --i)
	{
		ans[i] = Query(1, pre[i] + 1);  //从后往前推断出每次的最后一个数字
	}

	for (int i =1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}