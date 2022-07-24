#include<iostream>
#include<cstring>
using namespace std;
int M, N, T;
char map[211][211];
bool visited[211][211][10];
int m = 0, n = 0;
int p = 0, q = 0;
bool flag = false;//判断是否追上了佐助
struct MAP
{
	int m, n;
	int t;
	int f;
}queue[50000];
MAP* head = queue;
MAP* tail = queue + 1;
int DIRECTION[4][2] = {
	{0,-1},
	{0,1},
	{-1,0},
	{1,0}
};
int main()
{
	cin >> M >> N >> T;
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> map[i][j];
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			if (map[i][j] == '@') { m = i; n = j; break; }//鸣人的位置
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			if (map[i][j] == '+') { p = i; q = j; break; }//佐助的位置
	for (int i = 1; i <= 200; ++i)
		for (int j = 1; j <= 200; ++j)
			for (int k = 0; k <= 9; ++k)
				visited[i][j][k] = false;
	visited[m][n][T] = true;
	queue[0].m = m;
	queue[0].n = n;
	queue[0].t = T;
	while (head < tail)
	{
		int m = head->m;
		int n = head->n;
		int t = head->t;
		int index = head - queue;
		if (m == p && n == q)
		{
			flag = true;
			break;
		}	
		else
			head++;
		for (int i = 0; i < 4; ++i)
		{
			int x = m + DIRECTION[i][0];
			int y = n + DIRECTION[i][1];
			if (x<1 || x>M || y<1 || y>N || visited[x][y][t])
				continue;
			visited[x][y][t] = true;
			if (map[x][y] == '#' && t == 0)
				continue;
			if (map[x][y] == '+' || map[x][y] == '*')
			{
				tail->m = x;
				tail->n = y;
				tail->t = t;
				tail->f = index;
				tail++;
			}
			if (map[x][y] == '#')
			{
				tail->m = x;
				tail->n = y;
				tail->t = t - 1;
				tail->f = index;
				tail++;
			}
		}
	}
	if (flag)
	{
		int count = 0;
		while ((head - queue) != 0)
		{
			int gap = (head - queue) - head->f;
			head = head - gap;
			count++;
		}
		cout << count;
	}
	else
		cout << -1;
	return 0;
}