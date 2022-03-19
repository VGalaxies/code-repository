#include<iostream>
using namespace std;
int ori[101][101];
int dp[101];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> ori[i][j];
	for (int i = 1; i <= n; ++i)//³õÊ¼»¯
		dp[i] = ori[n][i];
	for (int i = n - 1; i >= 1; --i)
		for (int j = 1; j <= i; ++j)
			dp[j] = max(dp[j] + ori[i][j], dp[j + 1] + ori[i][j]);
	cout << dp[1];
	return 0;
}