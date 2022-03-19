#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int n;
int DP[20][20];
int main() {
	cin >> n;
	for (int i = 0; i <= n; i++)
		DP[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			if (i == j)
				DP[i][j] = DP[i - 1][j];
			else 
				DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
		}
	cout << DP[n][n];
}