#include<iostream>
#include<cstring>
using namespace std;
char ori[25][25];
bool judge[25][25];
int ans = 0;
int W, H;
void Dfs(int i, int j)
{
	if (judge[i][j] == true)
		return;
	ans++;
	judge[i][j] = true;
	if (i > 1 && judge[i-1][j] == false && ori[i - 1][j] == '.')
		Dfs(i - 1, j);
	if (i < H && judge[i+1][j] == false && ori[i + 1][j] == '.')
		Dfs(i + 1, j);
	if (j > 1 && judge[i][j-1] == false && ori[i][j - 1] == '.')
		Dfs(i, j - 1);
	if (j < W && judge[i][j+1] == false && ori[i][j + 1] == '.')
		Dfs(i, j + 1);
}
int main()
{
	while (cin >> W >> H && (W || H))
	{
		memset(ori, 0, sizeof(ori));
		memset(judge, 0, sizeof(judge));
		ans = 0;
		for (int i = 1; i <= H; ++i)
			for (int j = 1; j <= W; ++j)
				cin >> ori[i][j];
		int x = 0;
		int y = 0;
		for (int i = 1; i <= H; ++i)
		{
			for (int j = 1; j <= W; ++j)
			{
				if (ori[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		Dfs(x, y);
		cout << ans << endl;
	}
	return 0;
}