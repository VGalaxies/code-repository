#include<iostream>
#include<cstring>
using namespace std;
char A[250];
char B[250];
char C[500];
bool dp[250][250];//表示s1的前i个字符和s2的前j个字符能否组成s3的前i+j个字符
bool ans[1010];
int main()
{
	int n;
	cin >> n;
	int order = 0;
	while (n--)
	{
		if (!order)
			cin.get();
		cin.getline(A, 201, ' ');
		cin.getline(B, 201, ' ');
		cin.getline(C, 401);
		int len_a = strlen(A);
		int len_b = strlen(B);
		int len_c = strlen(C);
		dp[0][0] = 1;
		for (int i = 1; i <= len_a; ++i)
			if (dp[i - 1][0] && A[i - 1] == C[i - 1])
				dp[i][0] = 1;
		for (int j = 1; j <= len_b; ++j)
			if (dp[0][j-1] && B[j - 1] == C[j - 1])
				dp[0][j] = 1;
		for (int i = 1; i <= len_a; ++i)
		{
			for (int j = 1; j <= len_b; ++j)
			{
				if (dp[i - 1][j] && A[i - 1] == C[i + j - 1] || dp[i][j - 1] && B[j - 1] == C[i + j - 1])
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			}
		}
		if (dp[len_a][len_b])
			ans[order++] = 1;
		else
			ans[order++] = 0;
		memset(dp, 0, sizeof(dp));
	}
	for (int i = 0; i < order; ++i)
	{
		if (ans[i])
			cout << "Data set " << i+1 << ": yes" << endl;
		else
			cout << "Data set " << i+1 << ": no" << endl;
	}
	return 0;
}