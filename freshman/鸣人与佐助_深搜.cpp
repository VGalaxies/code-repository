#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int M, N, T;
char map[211][211];
bool visited[211][211];
int midSteps[210][210][20];
int minTime = 1 << 30;
int totalTime;
int ms = 0, ns = 0;
int ss = 0, ts = 0;
int DIRECTION[4][2] = {
	{0,-1},
	{0,1},
	{-1,0},
	{1,0}
};
void Dfs(int m, int n, int t)
//鸣人在第m行第n列，有t个查克拉
{
	if (t < 0)
		return;
	if (totalTime + abs(m - ss) + abs(n - ts) >= minTime)//带预见最优性剪枝
		return;
	if (totalTime > midSteps[m][n][t])
		return;
	midSteps[m][n][t] = min(midSteps[m][n][t], totalTime);//
	for (int i = 0; i < 4; ++i)
	{
		int x = m + DIRECTION[i][0];
		int y = n + DIRECTION[i][1];
		if (x<1 || x>M || y<1 || y>N || visited[x][y])
			continue;
		if (map[x][y] == '*')
		{
			visited[x][y] = true;
			totalTime++;
			Dfs(x, y, t);
			totalTime--;
			visited[x][y] = false;
		}
		if (map[x][y] == '#')
		{
			visited[x][y] = true;
			totalTime++;
			Dfs(x, y, t - 1);
			totalTime--;
			visited[x][y] = false;
		}
		if (map[x][y] == '+')
		{
			totalTime++;
			minTime = min(minTime, totalTime);
			totalTime--;
			return;
		}
	}
}
int main()
{
	cin >> M >> N >> T;
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> map[i][j];
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			if (map[i][j] == '@') { ms = i; ns = j; break; }//鸣人的位置
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			if (map[i][j] == '+') { ss = i; ts = j; break; }//佐助的位置
	totalTime = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= 200; ++i)
		for (int j = 1; j <= 200; ++j)
			for (int k = 0; k <= 9; ++k)
				midSteps[i][j][k] = 1 << 30;
	visited[ms][ns] = true;
	Dfs(ms, ns, T);
	if (minTime == 1 << 30)
		cout << -1;
	else
		cout << minTime;
}