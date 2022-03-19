/*
1、算出2的多少次幂最接近给出的n；
2、用原来n的数减去2的幂，如果这个数大于2，继续对新的n进行搜索；
3、如果幂大于2，对幂进行上述搜索；
4/一旦输入函数的数为0（2的0次幂）或1（2的1次幂）或2（2的二次幂），输出；
*/
#include<iostream>
using namespace std;
void Fun(int n)
{
	int power = 1, index = 0;//2^index=power
	while (power <= n)
	{
		power *= 2;
		index++;
	}
	if (n == 1)
		cout << "2(0)";
	else if (n == 2)
		cout << "2";
	else if (n == 3)//3应单独讨论
		cout << "2+2(0)";
	else if (n == power / 2) //n为2的幂次,且n>=4,注意这种情况下循环多进行了一次
	{
		cout << "2(";
		Fun(index - 1);//处理指数
		cout << ")";
	}
	else
	{
		cout << "2(";
		Fun(index - 1);//处理指数
		cout << ")+";//注意括号和加号位置
		Fun(n - power / 2);//用原来n的数减去2的幂，继续递归
	}
}
int main()
{
	int n;
	cin >> n;
	Fun(n);
	return 0;
}