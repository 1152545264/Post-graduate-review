#include<iostream>
#include <vector>
using namespace  std;

static const int Max = 10000;
static struct
{
	int l, r, len;
}tree[Max<<2];

static int pre[Max], ans[Max];

void Build(int left, int right, int u)  //�����߶����ĺ���
{
	tree[u].l = left;
	tree[u].r = right;
	tree[u].len = right - left + 1;
	if (left == right )  //�ݹ麯���ĳ���
	{
		return;
	}

	Build(left, (left + right) >> 1, u << 1);  //�ݹ鹹��������
	Build(((left + right) >> 1) + 1, right, (u << 1) + 1); //�ݹ鹹��������
}

int Query(int u, int num)  //�߶����Ĳ�ѯ+ά������������ֵΪ��ǰ���������num��Ԫ��
{
	tree[u].len--;  //�Է��ʵ�������ά��len�������������ǰ�����ڵ�ţ����������1
	if (tree[u].l == tree[u].r	)
	{
		return tree[u].l;
	}
	//���1������������ţ�ĸ�������������Ҫ��ѯ��������������� num - tree[u<<1].len ��Ԫ��
	if (tree[u<<1].len	 < num	)
	{
		return Query( (u << 1) + 1, num - tree[u << 1].len);
	}
	if (tree[u<<1].len >= num)    //����������ţ�������㹻�������ɲ�ѯ���������������num��Ԫ��
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
		ans[i] = Query(1, pre[i] + 1);  //�Ӻ���ǰ�ƶϳ�ÿ�ε����һ������
	}

	for (int i =1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}