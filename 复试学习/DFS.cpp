// 复试学习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>

using namespace std;

static int num = 0;
static int dir[][2] = {
	{1,0},{-1,0},
	{0,1},{0,-1},
};


static bool check(int dx, int dy) 
{
	if (dx >= 0 && dx <= 10 &&
		dy >= 0 && dy <= 10
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

static void DFS(vector<vector<char> >& room, int dx, int dy)
{
	room[dx][dy] = '#';
	++num;

	for (int i = 0; i < 4; ++i)
	{
		int newx = dx + dir[i][0];
		int newy = dx + dir[i][1];
		if (check(newx, newy) && room[newx][newy] == '.')
		{
			DFS(room, newx, newy);
		}
	}
}

int main1()
{
	std::cout << "Hello World!\n"; 
	return 0;
}

