#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, t, i, j, k;
int a[1005], b[1005], dp[1005][1005];
int main()
{
	scanf("%d %d %d", &n, &m, &t);
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= t; i++)
		scanf("%d %d", &a[i], &b[i]);
	for (i = 1; i <= t; i++) {
		for (j = n; j >= a[i]; j--)
			for (k = m; k >= b[i]; k--)
				dp[j][k] = max(dp[j][k], dp[j - a[i]][k - b[i]] + 1);
		//Print DP Table
		/*for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j)
				printf("%d", dp[i][j]);
			printf("\n");
		}
		printf("\n");*/
	}
	for (i = 0; i <= m; i++)//注意i从0开始
		if (dp[n][i] == dp[n][m]){
			printf("%d %d\n", dp[n][m], m - i);
			break;
		}
}