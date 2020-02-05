#include<iostream>
#include <map>

using namespace std;
static map<int, int> mp;


static int main7()
{
	int n;
	while (~scanf("%d",&n) && n)
	{
		mp.clear();
		mp[1e9] = 1;   //等级到和尚的id的映射
		while (n--)
		{
			int id, g;  //新和尚的id和等级g
			scanf("%d%d", &id, &g);
			mp[g] = id;  //新和尚入队
			int ans = 0;
			auto it = mp.find(g);  //找到排好序的位置

			if (it == mp.begin())
			{
				ans = (++it)->second;
			}
			else
			{
				auto it2 = it;  //it->first 为map的key值，second为map的value值
				--it2; ++it;
				if ( g - it2->first <= it->first - g )  //等级接近的前后两个老和尚
				{
					ans = it2->second;
				}
				else
				{
					ans = it->second;
				}
			}
			cout << id << ' ' << ans << endl;
		}
	}
	return 0;
}