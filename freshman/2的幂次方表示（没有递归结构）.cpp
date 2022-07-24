//并且2被输出成了2(1)
#include<iostream>
using namespace std;
int power(int n, int a)//乘方计算
{
	if (a == 0)
		return 1;
	else
	{
		int result = 1;
		for (int i = 1; i <= a; ++i)
		{
			result *= n;
		}
		return result;
	}
}
void convert(int n,int b[])//10进制转换为2进制（16位之内）
{
	int a[17] = { 0 };
	for (int i = 15; i >= 0; --i)
	{
		if (n / power(2, i) != 0)
		{
			a[i] = 1;
			n = n - power(2, i);
		}	
		else
		{
			a[i] = 0;
		}
	}
	for (int i = 15; i >= 0; --i)
	{
		b[i] = a[i];
	}
}
void output(int* b)
{
	int c[17] = { 0 };
	int num = 0;
	for (int i = 15; i >= 0; --i)
	{
		if (b[i] == 1)
			num++;
	}
	for (int i = 15; i >= 0; --i)
	{
		int count = 0;
		if (b[i] == 1)
		{
			for (int j = i; j >= 0; --j)//判断b[i]是否为二进制表示中最后一个1
				if (b[j] == 1)
					count++;
			if (count == 1)
				cout << "2(" << i << ")";
			else
				cout << "2(" << i << ")+";
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int b[17] = { 0 };
	convert(n, b);
	for (int i = 15; i >= 0; --i)
	{
		cout << b[i];
	}
	cout << endl;
	output(b);
	return 0;
}