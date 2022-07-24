#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int n, m, k;
int map[1010][1010];
int DP[1010][1010];
bool peak(int x, int y) {
	if (map[x - 1][y] > map[x][y] || map[x + 1][y] > map[x][y]
		|| map[x][y - 1] > map[x][y] || map[x][y + 1] > map[x][y])
		return false;
	return true;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
		}
	}
	memset(DP, 0x3f, sizeof(DP));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (peak(i, j))
				DP[i][j] = 0;
			else
				DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i - 1][j + 1])) + 1;
		}
		
	}
	/*for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}*/
	int tmp_x, tmp_y;
	for (int i = 0; i < k; ++i) {
		cin >> tmp_x >> tmp_y;
		if (DP[tmp_x][tmp_y] <= 10000)
			cout << DP[tmp_x][tmp_y] << endl;
		else
			cout << "Pool Babingbaboom!" << endl;
	}
}