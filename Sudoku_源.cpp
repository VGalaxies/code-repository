#include <iostream>
using namespace std;

int num, v[100][2], map[10][10];
//bool pd[10][10];	//判断输入的时候是否为零

bool judge(int x, int y, int k) {
	int i, j, it, jt;
	for (i = 0; i < 9; i++) {
		if (map[i][y] == k) return false;
		if (map[x][i] == k) return false;
	}
	it = (x / 3) * 3;
	jt = (y / 3) * 3;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (map[i + it][j + jt] == k)
				return false;
	return true;
}

int dfs(int cap) {
	int i, x, y;
	if (cap < 0) return 1;

	for (i = 1; i <= 9; i++) {
		x = v[cap][0];
		y = v[cap][1];
		if (judge(x, y, i)) {
			map[x][y] = i;
			if (dfs(cap - 1)) return 1;
			map[x][y] = 0;
		}
	}
	return 0;
}

int main() {
	int t, i, j;
	char c;
	scanf("%d\n", &t);
	while (t--) {
		num = 0;
		for (i = 0; i < 9; i++, getchar())
			for (j = 0; j < 9; j++) {
				scanf("%c", &c);
				map[i][j] = c - '0';
				if (map[i][j] == 0) {		//将为空的点的坐标全部记录下来，等下需要用暴力解决
					v[num][0] = i;
					v[num++][1] = j;
				}
			}
		dfs(num - 1);
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++)
				printf("%d", map[i][j]);
			printf("\n");
		}
	}
	return 0;
