#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 6010;
int n, son, fa, root;
int val[N];
int dp[N][2];//dp[N][0]不选该结点，dp[N][1]选该结点
vector<int> tree[N];
void dfs(int rt) {
	if (tree[rt].empty()) {
		dp[rt][0] = 0;
		dp[rt][1] = val[rt];
		return;
	}
	for (auto i : tree[rt]) {
		dfs(i);
		dp[rt][1] += dp[i][0];
		dp[rt][0] += max(dp[i][0], dp[i][1]);
	}
	dp[rt][1] += val[rt];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> val[i];
	while (cin >> son >> fa && son && fa) {
		tree[fa].push_back(son);
		if (root == son || !root)
			root = fa;
	}
	dfs(root);
	cout << max(dp[root][0], dp[root][1]);
}