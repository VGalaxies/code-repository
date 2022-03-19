#include<iostream>
using namespace std;
int n, k;
char ori[10][10];
char copy_ori[10][10];
int ans = 0;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> ori[i][j];
	for (int i = 1; i <= n - k + 1; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (ori[i][j] != '#')
				continue;
			int tmp = k;
			for (int s = 1; s <= n; ++s)
				for (int t = 1; t <= n; ++t)
					copy_ori[s][t] = ori[s][t];
			copy_ori[i][j] = '*';
			tmp--;
			if (!tmp)
			{
				ans++;
				break;
			}
			for (int s = i + 1; s <= n; ++s)
			{
				bool judge = true;
				for (int t = 1; t <= n; ++t)
				{
					for (int h = 1; h <= i; ++h)
					{
						if (copy_ori[h][t] == '*')
							judge = false;
					}
					if (copy_ori[s][t] == '#' && judge)
					{
						copy_ori[s][t] = '*';
						tmp--;
						if (!tmp)
						{
							ans++;
							break;
						}
					}
				}
			}
		}
	}
	cout << ans;
}
