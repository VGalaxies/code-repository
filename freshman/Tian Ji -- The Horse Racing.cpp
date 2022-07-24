#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
struct Node
{
	int speed;
	int owner;
}ori[2020];
bool judge[2020];
struct rule
{
	bool operator()(const Node& a, const Node& b)const {
		if (a.speed == b.speed)
			return a.owner < b.owner;
		else
			return a.speed < b.speed;
	}
};
int main()
{
	while (cin >> n && n != 0)
	{
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> ori[i].speed;
			ori[i].owner = 1;
		}
		for (int i = n + 1; i <= 2 * n; ++i)
		{
			cin >> ori[i].speed;
			ori[i].owner = 0;
		}
		sort(ori + 1, ori + 2 * n + 1, rule());
		memset(judge, true, sizeof(judge));
		for (int i = 1; i <= 2 * n; ++i)
		{
			if (ori[i].owner == 1 && judge[i])
			{
				for (int j = i - 1; j >= 1; --j)
				{
					if (ori[j].speed == ori[i].speed)
						continue;
					if (judge[i] && judge[j] && ori[i].owner != ori[j].owner)
					{
						ans++;
						judge[i] = false;
						judge[j] = false;
						break;
					}
				}
			}
		}
		for (int i = 1; i <= 2 * n; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				if (ori[i].speed == ori[j].speed && judge[i] && judge[j] && ori[i].owner!=ori[j].owner)
				{
					judge[i] = false;
					judge[j] = false;
				}
			}
		}
		int tmp = 0;
		for (int i = 1; i <= 2 * n; ++i)
		{
			if (judge[i])
			{
				tmp++;
				judge[i] = false;
			}
		}	
		tmp /= 2;
		ans -= tmp;
		ans *= 200;
		cout << ans << endl;
	}
	return 0;
}
