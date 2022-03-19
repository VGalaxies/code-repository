#include<iostream>
#include<cstring>
using namespace std;
char A[250];
char B[250];
char C[500];
bool dp[250][250];//表示s1的前i个字符和s2的前j个字符能否组成s3的前i+j个字符
int main()
{
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
	cout << dp[i][j];
	//for (int i = 0; i <= len_a; ++i)
	//{
	//	for (int j = 0; j <= len_b; ++j)
	//	{
	//		cout << dp[i][j] << " ";
	//		if (j == len_b)
	//			cout << endl;
	//	}
	//}
	return 0;
}
