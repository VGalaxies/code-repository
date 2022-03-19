#include<iostream>
#include<algorithm>
using namespace std;
int map[360];
int dp[45][45][45][45];
int m, n, a, b, c, d, tmp;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> map[i];
	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		switch (tmp){
			case 1:a++; break;
			case 2:b++; break;
			case 3:c++; break;
			case 4:d++; break;
		}
	}
	dp[0][0][0][0] = map[0];
	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= b; ++j) {
			for (int k = 0; k <= c; ++k) {
				for (int l = 0; l <= d; ++l) {
					if (i)
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + map[i + 2 * j + 3 * k + 4 * l]);
					if (j)
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + map[i + 2 * j + 3 * k + 4 * l]);
					if (k)
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + map[i + 2 * j + 3 * k + 4 * l]);
					if (l)
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + map[i + 2 * j + 3 * k + 4 * l]);
				}
			}	
		}
	}
	cout << dp[a][b][c][d];
}