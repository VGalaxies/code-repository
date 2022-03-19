/*三个结构的互相的，间接的递归
表达式-项-加减
项-因子-乘除
因子-表达式-整数
*/
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
using namespace std; 
int factor_value(); 
int term_value();
int expression_value();
int main()
{
	cout << expression_value() << endl; 
	return 0;
}
int expression_value()	//求一个表达式的值
{
	int result = term_value();//求第一项的值
	bool more = true;
	while (more)
	{
		char op = cin.peek();//看一个字符,不取走
		if (op == '+' || op == '-')
		{
			cin.get();//从输入中取走一个字符
			int value = term_value();
			if (op == '+')
				result += value;
			else
				result -= value;

		}
		else
			more = false;
	}
	return result;
}
int term_value()  //求一个项的值
{
	int result = factor_value();  //求第一个因子的值
	bool more = true;
	while (more)
	{
		char op = cin.peek();
		if (op == '*' || op == '/')
		{
			cin.get();
			int value = factor_value();
			if (op == '*')
				result *= value;
			else
				result /= value;

		}
		else
			more = false;
	}
	return result;
}
int factor_value()
{
	int result = 0;
	char c = cin.peek();
	if (c == '(')
	{
		cin.get();
		result = expression_value();
		cin.get();
	}
	else
	{
		while (isdigit(c))//检查参数是否为十进制数字字符
		{
			result = 10 * result + c - '0';
			cin.get();
			c = cin.peek();
		}
	}
	return result;
}