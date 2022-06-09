#include<cstdio>
#include<iostream>
#include<cstring>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ori;
int n, k, m;
int remain_num;
int main() {
	cin >> n >> k >> m;//kË³,mÄæ
	for (int i = 1; i <= n; ++i)
		ori.push_back(i);
	int pre = 1, anti_pre = n;
	vector<int>::iterator ptr = ori.begin();
	while (!ori.empty()) {
		sort(ori.begin(), ori.end());
		ptr = upper_bound(ori.begin(), ori.end(), pre - 1);
		if (ptr + (k - 1) % ori.size() >= ori.end()) {
			ptr -= ori.size();
		}
		ptr += (k - 1) % ori.size();
		pre = *ptr;

		ptr = lower_bound(ori.begin(), ori.end(), anti_pre);
		if (ptr - (m - 1) % ori.size() < ori.begin()) {
			ptr += ori.size();
		}
		ptr -= (m - 1) % ori.size();
		anti_pre = *ptr;

		if (pre == anti_pre) {
			printf("%d ", pre);
			return 0;
		}
		else {
			printf("%d %d ", pre, anti_pre);
			ori.erase(ptr);
			anti_pre--;
			ptr = upper_bound(ori.begin(), ori.end(), pre - 1);
			ori.erase(ptr);
		}
	}
}