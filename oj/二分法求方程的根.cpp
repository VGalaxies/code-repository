/*
求下面方程的一个根：f(x) = x3-5x2+10x-80 = 0
若求出的根是a，则要求 |f(a)| <= 10-6
*/
#include<iostream>
#include<cmath>
using namespace std;
const double EPS = 1e-6;
double function(double x)
{
	return (x * x * x - 5 * x * x + 10 * x - 80);
}
int main()
{
	double L = 0;
	double R = 100;
	double root = (L + R) / 2;
	int count = 0;
	while (abs(function(root))>=EPS)
	{
		if (function(root) < 0)
			L = root;
		else if (function(root) > 0)
			R = root;
		root = (L + R) / 2;
		count++;
	}
	cout << root <<endl;
	cout << count;
	return 0;
}