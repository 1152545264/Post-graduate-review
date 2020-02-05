#include<iostream>
using namespace  std;

static int val[1010]; 
static int pos, n;

static bool ida(int now, int depth)
{
	if ( now > depth)  // IDDFS:大于当前设定的DFS深度，退出
	{
		return false;
	}

	if (val[pos] << (depth - now) < n)     //估价函数：用最快的倍增都不能达到n，退出
	{
		return false;
	}

	if (val[pos] == n)  //当前结果等于n，搜索结束
	{
		return true;
	}

	++pos;

	for (int i = 0; i < pos ; ++i)
	{
		val[pos] = val[pos - 1] + val[i];   //上一个数与前面所有数相加
		if (ida(now+1,depth))
		{
			return true;
		}
		val[pos] = abs(val[pos - 1] - val[i]);  //上一个数与前面所有的数相减
		if (ida(now + 1, depth))
		{
			return true;
		}
	}
	--pos;
	return false;
}

int main3() 
{
	while (cin >>n && n)
	{
		int depth;
		for (depth = 0; ; ++depth)
		{
			val[pos = 0] = 1;
			if (ida(0,depth))
			{
				break;
			}
		}
		cout << depth << endl;
	}
	return 0;
}