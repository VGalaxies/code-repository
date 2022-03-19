/*
输入
输入数据包括多行，每行给出一组测试数据，包括4个小于10个正整数。最后一组测试数据中包括4个0，表示输入的结束，这组数据不用   处理。
输出
对于每一组测试数据，输出一行，如果可以得到24，输出“YES”；
否则，输出“NO”。
样例输入
5 5 5 1
1 1 4 2
0 0 0 0
样例输出
YES
NO

返回bool型变量
n个数算24，必有两个数要先算。这两个数算的结果，和剩余n-2个数，就构成了n-1个数求24的问题
枚举先算的两个数，以及这两个数的运算方式。
边界条件?
注意：浮点数比较是否相等，不能用 ==
*/
#include <iostream> 
#include <cmath> 
using namespace std; 
double a[5];
#define EPS	1e-6
bool isZero(double x)
{
	return fabs(x) <= EPS;
}
bool count24(double a[], int n)
{//用数组a里的 n个数，计算24
	if (n == 1) 
	{
		if (isZero(a[0] - 24))//最后的运算结果存储在a[0]中
			return true;
		else
			return false;
	}
	double b[5];
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j) 
		{ //枚举两个数的组合
			int m = 0; //还剩下m个数, m = n - 2
			for (int k = 0; k < n; ++k)
				if (k != i && k != j)
					b[m++] = a[k];//把其余数放入b 
			b[m] = a[i]+a[j];
			if (count24(b, m + 1))
				return true; 
			b[m] = a[i] - a[j]; 
			if (count24(b, m + 1))
				return true; 
			b[m] = a[j] - a[i]; 
			if (count24(b, m + 1))
				return true; 
			b[m] = a[i] * a[j]; 
			if (count24(b, m + 1))
				return true;
			if (!isZero(a[j])) 
			{
				b[m] = a[i] / a[j];
				if (count24(b, m + 1))
					return true;
			}
			if (!isZero(a[i])) 
			{
				b[m] = a[j] / a[i]; 
				if (count24(b, m + 1))
					return true;
			}
		}
	return false;
}
int main()
{
	while (true) 
	{
		for (int i = 0; i < 4; ++i)
			cin >> a[i];
		if (isZero(a[0]))//测试数据开头为0就结束
			break; 
		if (count24(a, 4))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;	
	}
	return 0;

	

	
}


	
