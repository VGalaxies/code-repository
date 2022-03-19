/*
输入
多组数据，每组数据一行
输出
针对每组数据，将其中的数输出来。每行一个数，保留小数点后面6位。
输入数据中只会有正数，不用考虑负号。两个数之间有至少一个非数字非小数点的字符。
*/
#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char* str)
{
	double n = 0;
    static char* p;//静态变量
    if (str) 
        p = str;
    while (*p && !(*p >= '0' && *p <= '9'))
        ++p;
    if (*p == 0)
        return -1;
	while (*p >= '0' && *p <= '9')
	{
		int tmp = *p-'0';//将字符转化为整数，经典！
		n = n * 10 + tmp;
		p++;
	}
	if (*p == '.')
	{
		double divisor = 10;//注意为double变量
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