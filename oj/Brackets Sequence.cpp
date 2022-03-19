#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[110][110];
string s;
void Output(int i, int j) {
	//此时不输出，直接返回
	if (i > j) {
		return;
	}
	//此时括号字符落单，原字符串中没有与之匹配的，直接为它配一个
	else if (i == j) {
		printf((s[i] == '(' || s[i] == ')') ? "()" : "[]");
		return;
	}
	//如果i与j匹配
	else if ((s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']') && dp[i][j] == dp[i + 1][j - 1]) {
		//先输出i
		printf("%c", s[i]);
		//再输出中间内容
		Output(i + 1, j - 1);
		//再输出j
		printf("%c", s[j]);
		return;
	}
	else {
		//枚举中转点，寻找最优的分割点（求dp数组时求好的答案）
		for (int k = i; k < j; ++k) {
			//找到某个最优的分割点
			if (dp[i][j] == dp[i][k] + dp[k + 1][j]) {
				//分割输出
				Output(i, k);
				Output(k + 1, j);
				return;
			}
		}
	}
}
int main() {
	while (cin >> s) {
		int total = s.size();
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < total; ++i)
			dp[i][i] = 1;
		for (int len = 1; len < total; ++len) {
			for (int st = 0; st < total - len; ++st) {
				int i = st, j = st + len;
				if (s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']')
					dp[i][j] = dp[i + 1][j - 1];
				else {
					for (int k = i; k <= j - 1; ++k) {
						dp[i][j] = (dp[i][j] == 0) ? (dp[i][k] + dp[k + 1][j])
							: min(dp[i][j], dp[i][k] + dp[k + 1][j]);
					}
				}
			}
		}
		Output(0, total - 1);
		printf("\n");
	}
}