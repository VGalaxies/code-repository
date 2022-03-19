#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int memo[20][20];
int DFS(int i, int j) {
	if (memo[i][j])
		return memo[i][j];
	if (i == 0)
		return 1;
	if (j > 0)
		memo[i][j] += DFS(i, j - 1);
	memo[i][j] += DFS(i - 1, j + 1);
	return memo[i][j];
}
int main() {
	int n;
	cin >> n;
	cout << DFS(n, 0);
}