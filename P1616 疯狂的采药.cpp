#include<iostream>
using namespace std;
int c[10010];
int w[10010];
unsigned long long dp[10000010];
int main() {
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; ++i)
		cin >> c[i] >> w[i];
	for (int i = 1; i <= m; ++i)
		for (int j = c[i]; j <= t; ++j)
			dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
	cout << dp[t];
}