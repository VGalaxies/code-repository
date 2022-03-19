#include<iostream>
#include<algorithm>
using namespace std;
int n, tmp, ans_max, ans_min = 1 << 30;
int dp_max[220][220];
int dp_min[220][220];
int sum[220];
int ori[110];
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> ori[i];
		sum[i] = sum[i - 1] + ori[i];
	}
	for (int i = n + 1; i <= 2 * n; ++i)
		sum[i] = sum[i - 1] + ori[i - n];

	for (int len = 0; len < 2 * n; ++len) {
		for (int st = 1; st <= 2 * n - len; ++st) {
			int i = st, j = st + len;
			for (int k = i; k <= j - 1; ++k) {
				dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + sum[j] - sum[i - 1]);
				if (dp_min[i][j] == 0)
					dp_min[i][j] = dp_min[i][k] + dp_min[k + 1][j] + sum[j] - sum[i - 1];
				else
					dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + sum[j] - sum[i - 1]);
			}
		}
	}
	for (int i = 1; i <= n+1; ++i) {
		ans_max = max(ans_max, dp_max[i][i + n - 1]);
		ans_min = min(ans_min, dp_min[i][i + n - 1]);
	}
	cout << ans_min << endl << ans_max;
}