#include<iostream>
using namespace std;
int f(int n)   //���n��λ��
{
	int i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return i;
}
void int_to_str(int n, char* str)
{
	char c;
	int i = 0;
	while (n != 0)
	{
		str[i] = n % 10 + '0';  //ASCII
		n = n / 10;
		i++;
	}
	for (int j = 0; j < i / 2; j++)  //˳��ߵ�
	{
		c = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = c;
	}
	str[i++] = '\0';//��ĩβ��\0
}
int main()
{
	int n;
	cin >> n;
	int i = f(n);
	char p[100];
	int_to_str(n, p);
	cout << p;
	return 0;
}