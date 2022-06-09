#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int n, len;
struct INFO {
	int l;
	int w;
}info[5010];
int dp[5010];
bool compare(const INFO& a, const INFO& b) {
	if (a.w == b.w)
		return a.l > b.l;
	return a.w > b.w;
}
int main() {
	//fstream cin("in.in");
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> info[i].l >> info[i].w;
	sort(info, info + n, compare);
	for (int i = 0; i < n; ++i) {
		if (dp[len] < info[i].l)
			dp[++len] = info[i].l;
		else
			*lower_bound(dp + 1, dp + len + 1, info[i].l) = info[i].l;
	}
	cout << len;
}