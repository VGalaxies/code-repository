#include<iostream>
using namespace std;
int a[1000];
int dp(int m, int k)//��ǰm����Ʒ�дճ�k�ķ�����
{
	if (k == 0)
		return 1;
	if (m <= 0)
		return 0;
	else
		return dp(m - 1, k) + dp(m - 1, k - a[m]);//ѡ���ǲ�ѡ��m����Ʒ
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