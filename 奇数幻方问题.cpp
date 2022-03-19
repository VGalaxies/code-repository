//奇数幻方问题
#include<iostream>
using namespace std;
int main()
{
	int n;
	int* p;
	cin >> n;
	p = new int[n * n];             //（伪）动态二维数组
	for (int i = 0; i < n*n; i++)   //初始化为0
		p[i] = 0;
	p[(n - 1) / 2] = 1;
	int* q = p + (n - 1) / 2;       //引入指针
	int count = 2;
	while (count <= n * n)
	{
		if (q == p + (n - 1))
		{
			q = q + n;
			*q = count;
			count++;
		}
		else if ((q - p) >= 0 && (q - p) <= n - 1)
		{
			q = p + n * (n - 1) + (q - p) + 1;
			*q = count;
			count++;
		}
		else if ((q+1-p)%n==0)
		{
			q = q - 2 * n + 1;
			*q = count;
			count++;
		}
		else if (*(q-n+1)==0)
		{
			q = q - n + 1;
			*q = count;
			count++;
		}
		else
		{
			q = q + n;
			*q = count;
			count++;
		}
	}
	int num = 1;
	for (int i = 0; i < n * n; i++, num++)
	{
		cout << p[i] << " ";
		if (num % n == 0)
			cout << endl;
	}
	return 0;
}