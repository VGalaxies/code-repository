#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int m, n;
int arr[1010][1010];
int color[1010][1010];
int ans[100010];
int DIRECTION_X[4] = { -1,1,0,0 };
int DIRECTION_Y[4] = { 0,0,1,-1 };
void DFS(int x, int y,int symbol,int index) {
	if (x<1 || x>n || y<1 || y>n || color[x][y] != -1 || arr[x][y] != symbol)
		return;
	color[x][y] = index;
	ans[index]++;
	DFS(x - 1, y, !symbol, index);
	DFS(x + 1, y, !symbol, index);
	DFS(x, y - 1, !symbol, index);
	DFS(x, y + 1, !symbol, index);
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
	memset(color, -1, sizeof(color));
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (color[x][y] == -1)
			DFS(x, y, arr[x][y], i);
		else
			ans[i] = ans[color[x][y]];
		printf("%d\n", ans[i]);
	}	
}