#include<iostream>
#include<cstring>
using namespace std;
int ori[55][55];
int color[55][55];
int m, n;
int num = 0;
int colorNum = 0;
int maxRoomArea = 0;
int area = 0;
void Dfs(int i, int j)
{
	if(color[i][j])
		return;
	area++;
	color[i][j] = colorNum;
	if (!(ori[i][j] & 1))//西
		Dfs(i, j - 1);
	if (!(ori[i][j] & 2))//北
		Dfs(i - 1, j);
	if (!(ori[i][j] & 4))//东
		Dfs(i, j + 1);
	if (!(ori[i][j] & 8))//南
		Dfs(i + 1, j);
}
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> ori[i][j];
	memset(color, 0, sizeof(color));
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			while (!color[i][j])
			{
				colorNum++;
				area = 0;
				Dfs(i, j);
				maxRoomArea = max(area, maxRoomArea);
			}
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << color[i][j];
		}
		cout << endl;
	}
	cout << colorNum << " " << maxRoomArea;
	return 0;
}