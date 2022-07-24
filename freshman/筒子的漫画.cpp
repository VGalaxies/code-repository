#include<iostream>
#include<cmath>
using namespace std;
long long int ori[10010];
long long int n, t, ans;
long long int R, L = 1e9 + 1;
inline bool judge(long long int x) {
	long long int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += ceil(ori[i] * 1.0 / x);
	if (sum <= t)
		return true;
	return false;
}
int main() {
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		cin >> ori[i];
		if (ori[i] < L)
			L = ori[i];
		if (ori[i] > R)
			R = ori[i];
	}
	while (L <= R) {
		long long int mid = L + ((R - L) >> 1);
		if (!judge(mid)) {
			L = mid + 1;
			ans = L;
		}
		else {
			R = mid - 1;
			ans = L;
		}
	}
	cout << ans;
}