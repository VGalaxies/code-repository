#include<cstdio>
#include<iostream>
using namespace std;
bool stu[30010];
int ans[30010];
int n, k, m;
int remain_num;
int main() {
	cin >> n >> k >> m;//kË³,mÄæ
	for (int i = 0; i < n; ++i)
		stu[i] = true;
	remain_num = n;
	int index_k = 0;
	int index_m = n - 1;
	while (remain_num >= 1) {
		int count_k = 0;//clockwise
		int count_m = 0;//anti-clockwise
		while (count_k < k) {
			if (index_k >= n)
				index_k -= n;
			if (stu[index_k])
				count_k++;
			if (count_k < k)
				index_k++;
		}
		while (count_m < m) {
			if (index_m < 0)
				index_m = n - index_m;
			if (stu[index_m])
				count_m++;
			if (count_m < m)
				index_m--;
		}
		if (index_k == index_m) {
			printf("%d ", index_k + 1);
			return 0;
		}
		else {
			stu[index_m] = false;
			remain_num--;
			stu[index_k] = false;
			remain_num--;
			printf("%d %d ", index_k + 1, index_m + 1);
		}
	}
	return 0;
}