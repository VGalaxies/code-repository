#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
int n;
int pre[10000];
int ans[10000];
int main() {
	cin >> n;
	vector<int> ori(n);
	iota(ori.begin(), ori.end(), 1);
	for (int i = 2; i <= n; ++i)
		cin >> pre[i];
	for (int i = n; i >= 1; --i) {
		ans[i] = ori[pre[i]];
		auto p = find(ori.begin(), ori.end(), ans[i]);
		ori.erase(p);
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << endl;
}