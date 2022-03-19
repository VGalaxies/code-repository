#include<iostream>
using namespace std;
int a[1000];
int dp(int m, int k)//从前m个物品中凑出k的方法数
{
	if (k == 0)
		return 1;
	if (m <= 0)
		return 0;
	else
		return dp(m - 1, k) + dp(m - 1, k - a[m]);//选还是不选第m件物品
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cout << dp(n, 40);
	return 0;
}