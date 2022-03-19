#include<iostream>
#include<cstring>
using namespace std;
int n, k;
char ori[10][10];
bool visited[10];
int ans;
void Dfs(int x, int p)
{
	if (p == 0)
	{
		ans++;
		return;
	}
	for (int i = x; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[j] && ori[i][j] == '#')
			{
				visited[j] = true;
				Dfs(i + 1, p - 1);//²»ÊÇDfs(x + 1, p - 1)
				visited[j] = false;
			}
		}
	}
}
int main()
{
	while (cin >> n >> k && !(n == -1 && k == -1))
	{
		ans = 0;
		memset(visited, 0, sizeof(visited));
		memset(ori, 0, sizeof(ori));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> ori[i][j];
		Dfs(0, k);
		cout << ans << endl;
	}
	return 0;
}