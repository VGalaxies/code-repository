/*
����
�������ݣ�ÿ������һ��
���
���ÿ�����ݣ������е����������ÿ��һ����������С�������6λ��
����������ֻ�������������ÿ��Ǹ��š�������֮��������һ�������ַ�С������ַ���
*/
#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char* str)
{
	double n = 0;
    static char* p;//��̬����
    if (str) 
        p = str;
    while (*p && !(*p >= '0' && *p <= '9'))
        ++p;
    if (*p == 0)
        return -1;
	while (*p >= '0' && *p <= '9')
	{
		int tmp = *p-'0';//���ַ�ת��Ϊ���������䣡
		n = n * 10 + tmp;
		p++;
	}
	if (*p == '.')
	{
		double divisor = 10;//ע��Ϊdouble����
		p++;
		while (*p >= '0' && *p <= '9')
		{
			int tmp = *p - '0';
			n += tmp / divisor;
			divisor *= 10;
			p++;
		}
	}
	return n;
}
int main()
{
	char line[300];
	while (cin.getline(line, 280)) {
		double n;
		n = GetDoubleFromString(line);
		while (n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}