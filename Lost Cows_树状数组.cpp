#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int pre[10000];
int ans[10000];
int arr[10000];
inline int lowbit(int x) {
	return x & -x;
}
inline void add(int x, int k) {
	for (int i = x; i <= n; i += lowbit(i)) {
		arr[i] += k;
	}
}
inline int query(int x) {
	int ans = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		ans += arr[i];
	}
	return ans;
}
int findpos(int x) {
	int L = 1, R = n, ans = 0;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (query(mid) < x) //找最小值，使条件为false
			L = mid + 1;
		else 
			R = mid - 1;
		ans = L;
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		scanf("%d", &pre[i]);
	for (int i = 1; i <= n; ++i)
		arr[i] = lowbit(i);
	for (int i = n; i >= 1; --i) {
		int x = findpos(pre[i] + 1);
		add(x, -1);
		ans[i] = x;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
}