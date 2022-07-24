#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;
int cases;
int n;
int money[100010];
int dp[100010];
int res[100010];
int DP(int a) {
	dp[0] = 0;
	dp[1] = money[1];
	for (int i = 2; i <= a; ++i)
		dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
	return dp[a];
}
int main() {
	scanf("%d", &cases);
	for (int i = 0; i < cases; ++i) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &money[i]);
		res[i] = DP(n);
	}
	for (int i = 0; i < cases; ++i)
		printf("%d\n", res[i]);
}