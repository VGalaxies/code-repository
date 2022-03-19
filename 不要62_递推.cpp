#include<iostream>
#include<algorithm>
const int LEN = 10;
int dp[LEN + 1][10]; // 表示i位数中，首位是j，符合要求的数的个数
int digit[LEN + 1];
using namespace std;
void init() {
	dp[0][0] = 1;
	for (int i = 1; i < LEN; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				if (j == 4 || j == 6 && k == 2)
					continue;
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
}
int solve(int len) {
	int ans = 0;
	for (int i = len; i >= 1; --i) {
		for (int j = 0; j < ((i == 1) ? digit[i] + 1 : digit[i]); ++j) {
			if (j == 4 || digit[i + 1] == 6 && j == 2)
				continue;
			ans += dp[i][j];
		}
		if (digit[i] == 4 || digit[i] == 2 && digit[i + 1] == 6)
			break;
	}
	return ans;
}
int aid(int x) {
	if (x == 0)
		return 1;
	int len = 0;
	memset(digit, 0, sizeof(digit));
	while (x) {
		digit[++len] = x % 10;
		x /= 10;
	}
	return solve(len);
}
int main() {
	ios::sync_with_stdio(false);
	int a, b;
	init();
	while (cin >> a >> b && a && b) {
		int l = aid(a - 1);
		int r = aid(b);
		cout << r - l << endl;
	}
}