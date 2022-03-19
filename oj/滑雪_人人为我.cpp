#include<iostream>
#include<algorithm>
using namespace std;
int ori[111][111];
int dpmax[111][111];//
struct info
{
	int x;
	int y;
	int height;
}order[11111];//一维数组存储所有的点
int R, C;
struct Rule
{
	bool operator() (const info& s1, const info& s2) const {
		return s1.height < s2.height;
	}
};
int main()
{
	cin >> R >> C;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cin >> ori[i][j];
			order[(i - 1) * C + j].x = i;
			order[(i - 1) * C + j].y = j;
			order[(i - 1) * C + j].height = ori[i][j];
			dpmax[i][j] = 1;
		}
	}
	sort(order + 1, order + R * C + 1, Rule());//按高度从小到大排序
	for (int i = 1; i <= R * C; ++i)
	{
		int x = order[i].x;
		int y = order[i].y;
		if (x > 1 && ori[x - 1][y] < ori[x][y])
			dpmax[x][y] = max(dpmax[x][y], dpmax[x - 1][y] + 1);
		if (y > 1 && ori[x][y - 1] < ori[x][y])
			dpmax[x][y] = max(dpmax[x][y], dpmax[x][y - 1] + 1);
		if (x < R && ori[x + 1][y] < ori[x][y])
			dpmax[x][y] = max(dpmax[x][y], dpmax[x + 1][y] + 1);
		if (y < C && ori[x][y + 1] < ori[x][y])
			dpmax[x][y] = max(dpmax[x][y], dpmax[x][y + 1] + 1);
	}
	int maxlen = 0;
	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
			maxlen = max(maxlen, dpmax[i][j]);
	cout << maxlen;
	return 0;
}