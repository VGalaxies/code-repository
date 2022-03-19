#include<iostream>
#include<algorithm>
using namespace std;
int n, len;
int a[100010];
int b[100010];
int f[100010];
int t[100010];
int dp[100010];
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) 
		cin >> b[i];
	for (int i = 1; i <= n; ++i)
		f[a[i]] = i;
	for (int i = 1; i <= n; ++i)
		t[i] = f[b[i]];
	/*
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		b[i] = a[b[i]];//»á·¢Éú¸²¸Ç
	}*/
	for (int i = 1; i <= n; ++i) {
		if (dp[len] < t[i])
			dp[++len] = t[i];
		else
			*lower_bound(dp + 1, dp + len + 1, t[i]) = t[i];
	}
	cout << len;
}