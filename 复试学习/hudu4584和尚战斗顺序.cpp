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
		mp[1e9] = 1;   //�ȼ������е�id��ӳ��
		while (n--)
		{
			int id, g;  //�º��е�id�͵ȼ�g
			scanf("%d%d", &id, &g);
			mp[g] = id;  //�º������
			int ans = 0;
			auto it = mp.find(g);  //�ҵ��ź����λ��

			if (it == mp.begin())
			{
				ans = (++it)->second;
			}
			else
			{
				auto it2 = it;  //it->first Ϊmap��keyֵ��secondΪmap��valueֵ
				--it2; ++it;
				if ( g - it2->first <= it->first - g )  //�ȼ��ӽ���ǰ�������Ϻ���
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