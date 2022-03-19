#include<iostream>
#include<cstring>
using namespace std;
int f(int n)  //判断素数
{
	int i = 2;
	while (i < n)
	{
		if (n % i == 0)
		{
			return 0;
			break;
		}
		++i;
	}
	if (i == n)
		return 1;
}
int main()
{
	char s[100];
	cin.getline(s,100);
	int sum[26] = { 0 };
	for (int i = 0; i < strlen(s); ++i)
	{
		sum[s[i] - 'a']++;   //一发入魂
	}
	int max = 0;
	int min = 100;
	for (int i = 0; i < 26; ++i)
	{
		if (sum[i] > max)
			max = sum[i];
		if (sum[i] < min&&sum[i]>0)
			min = sum[i];
	}
	int k = max - min;
	if (f(k) == 1)
		cout << "Lucky Word" << endl << k;
	else
		cout << "No Answer" << endl << '0';
	return 0;
}