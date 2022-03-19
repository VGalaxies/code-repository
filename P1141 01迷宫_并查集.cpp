#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int m, n;
int arr[1050][1050];
int DIRECTION_X[4] = { -1,1,0,0 };
int DIRECTION_Y[4] = { 0,0,1,-1 };
struct {
	int fa;
	int num;
}info[1000010];
int find(int x){
	if (x == info[x].fa)
		return x;
	else {
		info[x].fa = find(info[x].fa);  //父节点设为根节点
		return info[x].fa;         //返回父节点
	}
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
	for (int i = 1; i <= n * n; ++i) {
		info[i].fa = i;
		info[i].num = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k < 4; ++k) {
				int X = i + DIRECTION_X[k];
				int Y = j + DIRECTION_Y[k];
				if (X >= 1 && X <= n && Y >= 1 && Y <= n && arr[i][j] != arr[X][Y]) {
					int p = find((i - 1) * n + j);
					int q = find((X - 1) * n + Y);
					if (p != q) {
						info[q].fa = p;
						info[p].num += info[q].num;
					}
				}
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		cout << info[find((x - 1) * n + y)].num << endl;
	}
}