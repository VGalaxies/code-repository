#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int cases;
int n, k;
int pos_index;
int pos[110];
int profit[110];
int dp[1002000];
int res[1010];
int max_profit;
void DP() {
	for (int i = 1; i <= 1000; ++i)
		dp[i] = 0;
	for (int i = 1001; i <= 1000 + pos[n - 1]; ++i) {
		if (pos[pos_index] == i - 1000) {
			dp[i] = max(dp[i - 1], dp[i - k - 1] + profit[pos_index++]);//¾àÀë´óÓÚk
			max_profit = max(max_profit, dp[i]);
		}
		else {
			dp[i] = dp[i - 1];
			max_profit = max(max_profit, dp[i]);
		}
	}
}
int main() {
	scanf("%d", &cases);
	for (int i = 0; i < cases; ++i) {
		pos_index = 0;
		max_profit = 0;
		memset(profit, 0, sizeof(profit));
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", &pos[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &profit[i]);
		DP();
		res[i] = max_profit;
	}
	for (int i = 0; i < cases; ++i)
		printf("%d\n", res[i]);
}