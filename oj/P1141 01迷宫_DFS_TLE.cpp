#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int m, n;
int arr[1010][1010];
int visited[1010][1010];
int DIRECTION_X[4] = { -1,1,0,0 };
int DIRECTION_Y[4] = { 0,0,1,-1 };
int res;
int max_res;
void DFS(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int X = x + DIRECTION_X[i];
		int Y = y + DIRECTION_Y[i];
		if (X >= 1 && X <= n && Y >= 1 && Y <= n && !visited[X][Y] && arr[x][y]!=arr[X][Y]) {
			visited[X][Y] = true;
			res++;
			DFS(X, Y);
		}
	}
	max_res = max(max_res, res);
	return;
}
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
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		res = 1;
		max_res = 0;
		memset(visited, 0, sizeof(visited));
		visited[x][y] = true;
		DFS(x, y);
		cout << max_res << endl;
	}
}