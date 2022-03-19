/*
double atof(char *s);
将字符串s中的内容转换成实数返回。
比如，"12.34"就会转换成12.34。
如果s的格式不是一个实数 ，则返回0。

实际上实现的是从字符串中取数的拓展
若全不是数字则返回0
可以取正数和负数（但是受上述返回值限制，不能取0）
*/
#include<iostream>
using namespace std;
double my_atof(char* s)
{
	double result = 0;
	static char* p;
	if (s)
		p = s;
	while ((*p < '0' || *p>'9') && *p != '-'&&*p)
		p++;
	if (*p == 0)//无数可取
		return 0;
	if (*p == '-')
	{
		p++;
		while (*p >= '0' && *p <= '9')
		{
			int tmp = *p-'0';
			result = result * 10 + tmp;
			p++;
		}
		if (*p == '.')
		{
			p++;
			double divisor = 10;
			while(*p >= '0' && *p <= '9')
			{
				int tmp = *p-'0';
				result += tmp/divisor;
				divisor *= 10;
				p++;
			}
		}
		result = -result;
	}
	else
	{
		while (*p >= '0' && *p <= '9')
		{
			int tmp = *p - '0';
			result = result * 10 + tmp;
			p++;
		}
		if (*p == '.')
		{
			p++;
			double divisor = 10;
			while (*p >= '0' && *p <= '9')
			{
				int tmp = *p - '0';
				result += tmp / divisor;
				divisor *= 10;
				p++;
			}
		}
	}
	return result;
}
int main()
{
	char s[20];
	while (cin.getline(s, 20))
	{
		double n = my_atof(s);
		while (n == 0)
		{
			cout << 0;
			return 0;
		}
		while (n != 0)
		{
			cout << n << endl;
			n = my_atof(NULL);
		}
	}
	return 0;
}