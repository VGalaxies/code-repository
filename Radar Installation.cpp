#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n, d;
const double EPS = 0.000001;
struct island
{
	int x;
	int y;
}ori[1010];
struct section
{
	double l;
	double r;
	bool operator<(const section& a)const
	{return l < a.l;}
}trans[1010];
double last_r[1010];
bool visited[1010];
double trans_section(int y)
{
	return sqrt(d * d - y * y);
}
int output = 1;
int main()
{
	while (cin >> n >> d && (n != 0 || d != 0))
	{
		memset(ori, 0, sizeof(ori));
		memset(trans, 0, sizeof(trans));
		memset(last_r, 0, sizeof(last_r));
		memset(visited, 0, sizeof(visited));
		int ans = 1;
		bool flag = false;
		for (int i = 1; i <= n; ++i)
		{
			cin >> ori[i].x >> ori[i].y;
			if (ori[i].y > d)
				flag = true;
		}
		if (d <= 0 || flag)
		{
			cout << "Case " << output << ": " << -1;
			cout << endl;
			output++;
			continue;
		}
		for (int i = 1; i <= n; ++i)
		{
			trans[i].l = ori[i].x - trans_section(ori[i].y);
			trans[i].r = ori[i].x + trans_section(ori[i].y);
		}
		sort(trans + 1, trans + 1 + n);
		int i = 1;
		int j = 0;
		while (i <= n && j < n)
		{
			while (visited[i])
				i++;
			last_r[ans] = trans[i].r;
			for (j = i + 1; j <= n; ++j)
			{
				if (trans[j].l <= last_r[ans])
				{
					last_r[ans] = min(trans[j].r, last_r[ans]);//别忘了更新
					visited[j] = true;
				}
				else
				{
					ans++;
					i++;
					break;
				}
			}
		}
		cout << "Case " << output << ": " << ans;
		cout << endl;
		output++;
	}
}