#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static const int Max = 100000;
static int pre[Max] = { 0 }, tree[Max << 2] = { 0 }, ans[Max] = { 0 };
// tree 是用数组实现的完全二叉树

static void BuildTree(int n, int lastLeft) // lastLeft 主要是用于完全二叉树跳过空叶子节点
{
	int i;
	for (i = lastLeft; i < lastLeft + n ; ++i)  // 给二叉树的最后一行赋值，左边n个节点是n头牛
	{
		tree[i] = 1;
	}

	while (lastLeft != 1)
	{
		for (i = lastLeft << 1; i <lastLeft; ++i)  //从二叉树的最后一行倒推到根节点，根节点的值是牛的总数
		{
			tree[i] = tree[i << 1] + tree[(i << 1) + 1];
		}
		lastLeft <<= 1;
	}
}

int Query(int key, int num, int lastLeft) // 查询加维护，关键的一点是所求值为当前区间中左起第num个元素,lastLeft主要是用于\
										  完全二叉树跳过空叶子节点
{
	tree[key]--; 
	if (tree[key] == 0 && key >= lastLeft)
	{
		return key;
	}

	//情况1：左子区间的数字字数不够，则查询右子区间中左起第num - tree[key<<1]个元素
	int left = key << 1;
	if (tree[left] < num	)
	{
		return Query(left + 1, num - tree[left], lastLeft);
	}

	//情况2，左子区间的数字字数足够，依旧查询左子区间中左起第num个元素
	if (tree[left] >= num)
	{
		return Query(left, num, lastLeft);
	}

}

int main()
{
	int n, lastLeft, i;
	cin >> n; 
	pre[1] = 0;
	lastLeft = 1 << (int( log(n) / log(2) + 1 ) );  //计算二叉树的最后一层中的第一个

	for ( i = 2; i <= n; ++i)
	{
		cin >> pre[i];
	}

	BuildTree(n, lastLeft);

	for (i = n; i >= 1 ; --i)  //从后往前推断出每次最后一个数字
	{
		ans[i] = Query(1, pre[i] + 1, lastLeft) - lastLeft + 1;
	}

	for (i = n; i >= 1; --i)  
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}