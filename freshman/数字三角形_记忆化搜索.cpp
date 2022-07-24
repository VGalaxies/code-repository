#include<iostream>
using namespace std;
int ori[101][101];
int maxdp[101][101];
int n;
int maxsum(int i, int j)
{
	if (maxdp[i][j] != -1)
		return maxsum(i,j);//记忆体现在这里
	if (i == n)
		return ori[n][j];
	else
	{
		int x = maxsum(i+1, j);
		int y = maxsum(i+1, j + 1);
		return ori[i][j] + max(x, y);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
		{
			cin >> ori[i][j];
			maxdp[i][j] = -1;
		}
	cout << maxsum(1, 1);
	return 0;
			
}