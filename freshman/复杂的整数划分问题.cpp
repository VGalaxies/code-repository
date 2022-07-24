#include<iostream>
#include<cstring>
using namespace std;
#define N 55
int dp1[N][N];
int dp2[N];
int dp3[N];

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		for (int i = 1; i <= 50; ++i)
		{
			for (int j = 1; j <= 50; ++j)
			{
				if (i < j)
					dp1[i][j] = 0;
				else if (i == j)
					dp1[i][j] = 1;
				else
				{
					if (j == 1)
						dp1[i][j] = 1;
					else
						dp1[i][j] = dp1[i - j][j] + dp1[i - 1][j - 1];
				}
			}
		}
		cout << dp1[n][k];
		cout << endl;

		dp2[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = n; j >= i; j--)
				dp2[j] += dp2[j - i];
		cout << dp2[n];
		cout << endl;

		dp3[0] = 1;
		for (int i = 1; i <= n; i += 2)
			for (int j = i; j <= n; j++)
				dp3[j] += dp3[j - i];
		cout << dp3[n];
		cout << endl;
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		memset(dp3, 0, sizeof(dp3));
	}
	return 0;
}