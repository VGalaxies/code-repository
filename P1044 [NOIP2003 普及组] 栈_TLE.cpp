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
int ans;
void DFS(int steps,int status,int push) {
	if (steps == 2 * n) {
		ans++;
		return;
	}
	if (status <= n - 1 && push)
		DFS(steps + 1, status + 1, push - 1);
	if (status >= 1)
		DFS(steps + 1, status - 1, push);
}
int main() {
	cin >> n;
	DFS(1, 1, n - 1);
	cout << ans;
}