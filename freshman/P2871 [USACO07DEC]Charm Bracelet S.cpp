#include<iostream>
using namespace std;
int c[3500];
int w[3500];
int dp[13000];
int main(){
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> c[i] >> w[i];
	for (int i = 1; i <= N; ++i)
		for (int j = M; j >= c[i]; --j)
			dp[j] = max(dp[j], (dp[j - c[i]] + w[i]));
	cout << dp[M];
}