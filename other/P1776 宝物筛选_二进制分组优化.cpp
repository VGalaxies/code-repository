#include<iostream>
using namespace std;
int w[110];
int c[110];
int m[110];
int dp[40010];
int n, v;
int main() {
	cin >> n >> v;
	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> c[i] >> m[i];
	for (int i = 1; i <= n; ++i) {
		int num = min(v / c[i], m[i]);
		for (int j = 1; num; j << 2) {
			if (j > num)
				j = num;
			num -= j;
			for (int k = v; k >= j * c[i]; --k)
				dp[k] = max(dp[k], dp[k - j * c[i]] + j * w[i]);
		}
	}
	cout << dp[v];
}