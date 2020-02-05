#include<iostream>
#include <vector>	
using namespace std;

const int maxn = 1050;
int s[maxn] = { 0 };
void  init_set()
{
	for (int i = 1; i < maxn; ++i)
	{
		s[i] = i;
	}
}

int find_set(int x)
{
	if( x != s[x])
	{
		s[x] = find_set(s[x]);
		
	}
	return s[x];
}

void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);
	if (x  != y)   //将序号大的集合合并到小的集合上去
	{
		if (x < y) 
		{
			s[y] = x;
		}
		else
		{
			s[x] = y;
		}
	}
	return;
}


int main5() 
{

	int t, n, m, x, y;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;;
		init_set();
		for (int i = 1; i <= m ; ++i)
		{
			cin >> x >> y;
			union_set(x, y);
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (s[i] == i)
			{
				++ans;
			}
		}
		cout << ans << endl;
	}
	

	return 0;
}