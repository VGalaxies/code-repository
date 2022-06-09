#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag[15][15];
int T;
int n, m, x, y;
int count;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

void dfs(int x, int y, int c) {//已经在x，y，下一步是第c个
	if (c > m * n) {
		count++;
		return;
	}

	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
			continue;
		}
		if (!flag[xx][yy]) {
			flag[xx][yy] = c;
			dfs(xx, yy, c + 1);
			flag[xx][yy] = 0;
		}
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		memset(flag, 0, sizeof(flag));
		scanf("%d%d%d%d", &n, &m, &x, &y);
		count = 0;
		flag[x][y] = 1;
		dfs(x, y, 2);
		printf("%d\n", count);
	}

	return 0;
}