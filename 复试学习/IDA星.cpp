#include<iostream>
using namespace  std;

static int val[1010]; 
static int pos, n;

static bool ida(int now, int depth)
{
	if ( now > depth)  // IDDFS:���ڵ�ǰ�趨��DFS��ȣ��˳�
	{
		return false;
	}

	if (val[pos] << (depth - now) < n)     //���ۺ����������ı��������ܴﵽn���˳�
	{
		return false;
	}

	if (val[pos] == n)  //��ǰ�������n����������
	{
		return true;
	}

	++pos;

	for (int i = 0; i < pos ; ++i)
	{
		val[pos] = val[pos - 1] + val[i];   //��һ������ǰ�����������
		if (ida(now+1,depth))
		{
			return true;
		}
		val[pos] = abs(val[pos - 1] - val[i]);  //��һ������ǰ�����е������
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