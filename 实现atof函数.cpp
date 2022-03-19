/*
double atof(char *s);
���ַ���s�е�����ת����ʵ�����ء�
���磬"12.34"�ͻ�ת����12.34��
���s�ĸ�ʽ����һ��ʵ�� ���򷵻�0��

ʵ����ʵ�ֵ��Ǵ��ַ�����ȡ������չ
��ȫ���������򷵻�0
����ȡ�����͸�������������������ֵ���ƣ�����ȡ0��
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
	if (*p == 0)//������ȡ
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