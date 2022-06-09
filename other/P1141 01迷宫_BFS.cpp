#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
int m, n;
int arr[1010][1010];
int color[1010][1010];
int ans[100010];
int DIRECTION_X[4] = { -1,1,0,0 };
int DIRECTION_Y[4] = { 0,0,1,-1 };
struct info {
	int x;
	int y;
	info(int _x, int _y) :x(_x), y(_y) {}
};
int main() {
	cin >> n >> m;
	char tmp;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> tmp;
			if (tmp == '1')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
	queue<info> q;
	memset(color, -1, sizeof(color));
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (color[x][y] != -1)
			printf("%d\n", ans[color[x][y]]);
		else {
			int steps = 1;
			color[x][y] = i;
			q.push(info(x, y));
			while (!q.empty()) {
				info tmp = q.front();
				for (int j = 0; j < 4; ++j) {
					int X = tmp.x + DIRECTION_X[j];
					int Y = tmp.y + DIRECTION_Y[j];
					if (X >= 1 && X <= n && Y >= 1 && Y <= n && color[X][Y] != i && arr[tmp.x][tmp.y] != arr[X][Y]) {
						steps++;
						color[X][Y] = i;
						q.push(info(X, Y));
					}
				}
				q.pop();
			}
			ans[i] = steps;
			printf("%d\n", steps);
		}
	}
}