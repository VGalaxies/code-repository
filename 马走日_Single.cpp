#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int DIRECTION_X[8] = { -2,-2,-1,-1,1,1,2,2 };
int DIRECTION_Y[8] = { -1,1,-2,2,-2,2,-1,1 };
int visited[10][10];
int n, m, x, y;
int ans;
void DFS(int x, int y,int step) {
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d", visited[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	if (step > m * n) {
		ans++;
		return;
	}
	for (int i = 0; i < 8; ++i) {
		int X = x + DIRECTION_X[i];
		int Y = y + DIRECTION_Y[i];
		if (X >= 0 && X < n && Y >= 0 && Y < m && !visited[X][Y]) {
			visited[X][Y] = true;
			DFS(X, Y, step + 1);
			visited[X][Y] = false;
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &x, &y);
	visited[x][y] = true;
	DFS(x, y, 2);
	printf("%d", ans);
}