#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int m, n;
struct Info {
	int price;
	int level;
}info[30];
int dp[30010];
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
		cin >> info[i].price >> info[i].level;
	for (int i = 0; i < m; ++i)
		for (int j = n; j >= info[i].price; --j)
			dp[j] = max(dp[j], dp[j - info[i].price] + info[i].price * info[i].level);
	cout << dp[n];
}