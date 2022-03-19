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
int p[500];
int t[500][500];
int DP[500];
struct Info{
	int index;
	int p;
}info[500];
struct rule {
	bool operator()(const Info& a,const Info& b) const{
		return a.p < b.p;
	}
};
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> info[i].p;
		info[i].index = i;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> t[i][j];
	DP[0] = 0;
	info[0].index = 1;
	info[0].p = 0;
	sort(info + 1, info + n + 1, rule());
	for (int i = 1; i <= n; ++i) {
		int tmp_max = 0;
		for (int j = 0; j < i; ++j) {
			if (t[info[j].index][info[i].index] <= info[i].p - info[j].p)
				tmp_max = max(tmp_max, DP[j] + 1);
		}
		DP[i] = tmp_max;
	}
	int ans_max = 0;
	for (int i = 1; i <= n; ++i) {
		ans_max = max(ans_max, DP[i]);
	}
	cout << ans_max;
}