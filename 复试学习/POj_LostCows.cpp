#include<iostream>
#include<vector>
using namespace  std;
static const int maxn = 8005;

static int main7()
{
	int n, i, j, k;
	int pre[maxn], ans[maxn], num[maxn];
	cin >> n;
	pre[1] = 0;
	for ( i = 1; i <= n; ++i)
	{
		num[i] = i;
	}
	for ( i = 2; i <= n ; ++i)
	{
		cin >> pre[i];
	}

	for (i = n; i >= 1; --i)
	{
		k = 0;
		for (j =1; j <= n; ++j)
		{
			if (num[j] != -1)
			{
				++k;
				if (k == pre[i] +1)
				{
					ans[i] = num[j];
					num[j] = -1;
					break;
				}

			}
		}
	}
	return 0;
}