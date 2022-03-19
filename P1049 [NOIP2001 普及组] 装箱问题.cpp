#include<iostream>
using namespace std;
int v, n;
int volume[310];
int dp[20010];
int main() {
	cin >> v >> n;
	for (int i = 0; i < n; ++i)
		cin >> volume[i];
	for (int i = 0; i < n; ++i)
		for (int j = v; j >= volume[i]; j--)
			dp[j] = max(dp[j], dp[j - volume[i]] + volume[i]);			
	cout << v - dp[v];
}