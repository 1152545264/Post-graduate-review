#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static const int Max = 100000;
static int pre[Max] = { 0 }, tree[Max << 2] = { 0 }, ans[Max] = { 0 };
// tree ��������ʵ�ֵ���ȫ������

static void BuildTree(int n, int lastLeft) // lastLeft ��Ҫ��������ȫ������������Ҷ�ӽڵ�
{
	int i;
	for (i = lastLeft; i < lastLeft + n ; ++i)  // �������������һ�и�ֵ�����n���ڵ���nͷţ
	{
		tree[i] = 1;
	}

	while (lastLeft != 1)
	{
		for (i = lastLeft << 1; i <lastLeft; ++i)  //�Ӷ����������һ�е��Ƶ����ڵ㣬���ڵ��ֵ��ţ������
		{
			tree[i] = tree[i << 1] + tree[(i << 1) + 1];
		}
		lastLeft <<= 1;
	}
}

int Query(int key, int num, int lastLeft) // ��ѯ��ά�����ؼ���һ��������ֵΪ��ǰ�����������num��Ԫ��,lastLeft��Ҫ������\
										  ��ȫ������������Ҷ�ӽڵ�
{
	tree[key]--; 
	if (tree[key] == 0 && key >= lastLeft)
	{
		return key;
	}

	//���1����������������������������ѯ���������������num - tree[key<<1]��Ԫ��
	int left = key << 1;
	if (tree[left] < num	)
	{
		return Query(left + 1, num - tree[left], lastLeft);
	}

	//���2��������������������㹻�����ɲ�ѯ���������������num��Ԫ��
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
	lastLeft = 1 << (int( log(n) / log(2) + 1 ) );  //��������������һ���еĵ�һ��

	for ( i = 2; i <= n; ++i)
	{
		cin >> pre[i];
	}

	BuildTree(n, lastLeft);

	for (i = n; i >= 1 ; --i)  //�Ӻ���ǰ�ƶϳ�ÿ�����һ������
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