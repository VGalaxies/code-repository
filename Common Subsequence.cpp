#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string a, b;
int dp[1005][1005];
int main() {
	while (cin >> a >> b) {
		memset(dp, 0, sizeof(dp));
		int len_a = a.size();
		int len_b = b.size();
		for (int i = 1; i <= len_a; ++i) {
			for (int j = 1; j <= len_b; ++j) {
				if (a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << dp[len_a][len_b] << endl;
	}
}