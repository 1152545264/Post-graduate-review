#include<iostream>
#include<vector>
using namespace std;

static int n, tot = 0;
int col[12] ={ 0 };


static bool check(int c, int r)   //����Ƿ���Ѿ��źõĻʺ��ͻ
{
	for (int i = 0; i < r; ++i)
	{
		if (col[i] == r || (abs(col[i] - c) == abs(r-i) ) )
		{
			return false;
		}
	}
	return true;
}

static void DFS(int r) 
{
	if (r == n)
	{
		++tot;
		return;
	}
	for (int c = 0 ; c < n; ++c)
	{
		if (check(c,r))
		{
			col[c] = r;  // ��r�еĵ�C�зŻʺ�
			DFS(r + 1);
		}
	}
}


int main2()
{
	int ans[12] = { 0 };
	for (n = 0; n <= 10; ++n)
	{
		memset(col, 0, sizeof(col));
		tot = 0;
		DFS(0);
		ans[n] = tot;
	}

	cin >> n;

	if (n == 0)
	{
		return 0;
	}
	cout << ans[n] << endl;
	

	return 0;
}