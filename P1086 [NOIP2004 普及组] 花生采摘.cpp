#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int m, n, k;
int field[25][25];
struct info {
	int x;
	int y;
	int item;
}Info[625];
int info_index = 0;
struct Rule
{
	bool operator()(const info& a1, const info& a2) const { return a1.item > a2.item; }
};
int res[625];
int get_res(int pk) {
	int ans = 0;
	if (pk < res[0])
		return 0;
	if (k >= res[info_index - 1]) {
		for (int j = 0; j < info_index; ++j)
			ans += Info[j].item;
		return ans;
	}
	for (int i = 0; i < info_index; ++i) {
		if (k >= res[i] && k < res[i + 1]) {
			for (int j = 0; j <= i; ++j)
				ans += Info[j].item;
			return ans;
		}
	}
}

int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> field[i][j];
			if (field[i][j] != 0) {
				Info[info_index].x = i;
				Info[info_index].y = j;
				Info[info_index].item = field[i][j];
				info_index++;
			}
		}
	}
	sort(Info, Info + info_index, Rule());
	for (int i = 0; i < info_index; ++i) {
		if (i == 0)
			res[i] = 2 * (Info[i].x + 1) + 1;
		else
			res[i] = res[i - 1] - (Info[i - 1].x + 1) + 1 + (Info[i].x + 1) +
			abs(Info[i].x - Info[i - 1].x) + abs(Info[i].y - Info[i - 1].y);
	}
	/*for (int i = 0; i < info_index; ++i)
		printf("%d ", res[i]);*/
	printf("%d", get_res(k));
}