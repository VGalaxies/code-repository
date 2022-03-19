#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[110][110];
string s;
void Output(int i, int j) {
	//��ʱ�������ֱ�ӷ���
	if (i > j) {
		return;
	}
	//��ʱ�����ַ��䵥��ԭ�ַ�����û����֮ƥ��ģ�ֱ��Ϊ����һ��
	else if (i == j) {
		printf((s[i] == '(' || s[i] == ')') ? "()" : "[]");
		return;
	}
	//���i��jƥ��
	else if ((s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']') && dp[i][j] == dp[i + 1][j - 1]) {
		//�����i
		printf("%c", s[i]);
		//������м�����
		Output(i + 1, j - 1);
		//�����j
		printf("%c", s[j]);
		return;
	}
	else {
		//ö����ת�㣬Ѱ�����ŵķָ�㣨��dp����ʱ��õĴ𰸣�
		for (int k = i; k < j; ++k) {
			//�ҵ�ĳ�����ŵķָ��
			if (dp[i][j] == dp[i][k] + dp[k + 1][j]) {
				//�ָ����
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