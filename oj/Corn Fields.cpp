#include<iostream>
using namespace std;
int m, n;
long long ans;
int map[15];
int state[15][5000];
long long dp[15][5000];
int num[15];
bool check(int x, int m) {
	if (x & (x << 1) || (map[m] | x) != map[m])
		return false;
	else
		return true;
}
int main() {
	int tmp = 0;
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		int ans = 0;
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			ans += tmp << (n - 1 - j);
		}
		map[i] = ans;
	}
	for (int i = 0; i < m; ++i) {
		int total = 1 << n, count = 0;
		if (i == 0) {
			for (int j = 0; j < total; ++j) {
				if (check(j, i)) {
					state[i][count] = j;
					dp[i][count] = 1;
					count++;
				}
			}
			num[i] = count;
		}
		else {
			for (int j = 0; j < total; ++j) {
				if (check(j, i)) {
					state[i][count] = j;
					for (int k = 0; k < num[i - 1]; ++k) {
						if (!(j & state[i - 1][k])) {
							dp[i][count] += dp[i - 1][k];
						}
					}
					count++;
				}
			}
			num[i] = count;
		}
	}
	for (int i = 0; i < num[m - 1]; ++i)
		ans = (ans + dp[m - 1][i]) % 100000000;
	cout << ans;
}