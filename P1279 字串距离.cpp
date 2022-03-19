#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
int gap_space;
char a[2100];
char b[2100];
int dp[2100][2100];
int DP(int m, int n) {
	for (int i = 1; i <= m; i++)
		dp[i][0] = dp[i - 1][0] + gap_space;
	for (int i = 1; i <= n; i++)
		dp[0][i] = dp[0][i - 1] + gap_space;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			dp[i][j] = min(min(dp[i - 1][j] + gap_space, dp[i][j - 1] + gap_space), dp[i - 1][j - 1] + abs(b[j - 1] - a[i - 1]));
	//Print DP Table
	/*for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j)
			printf("%d ", dp[i][j]);
		printf("\n");
	}*/
	return dp[m][n];
}
int main() {
	scanf("%s%s%u", a, b, &gap_space);
	printf("%d", DP(strlen(a), strlen(b)));
}