#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int ans = 1;
struct Time
{
	int st;
	int ed;
	bool operator<(const Time& a)const
	{return ed < a.ed;}
}ori[111];
//struct rule
//{
//	bool operator()(const Time &a,const Time &b)const
//	{
//		return a.ed < b.ed;
//	}
//};
int main()
{

	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; ++i)
			cin >> ori[i].st >> ori[i].ed;
		sort(ori, ori + n);
		/*sort(ori, ori + n, rule());*/
		int tmp_ed = ori[0].ed;
		for (int i = 1; i < n; ++i)
		{
			if (ori[i].st >= tmp_ed)
			{
				ans++;
				tmp_ed = ori[i].ed;
			}
		}
		cout << ans << endl;
		ans = 1;
		memset(ori, 0, sizeof(ori));
	}
}