#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
using namespace std;
double exp() //读入一个逆波兰表达式，并计算其值
{
	
	char s[20]; 
	cin >> s; 
	switch (s[0]) 
	{
	case '+':	return exp() + exp();
	case '-':	return exp() - exp();
	case '*':	return exp() * exp();
	case '/':	return exp() / exp();
	default:	return atof(s); break;
	}
}
int main()
{
	printf("%lf", exp()); return 0;
}

