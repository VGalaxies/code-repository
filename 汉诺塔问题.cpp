//递归方法
#include<iostream>
using namespace std;
void hanoi(char x, char y, char z, int n)//x为初始，y为目标，z为中转
{
	if (n == 1)
		cout << "1:" << x << "→" << y << endl;
	else
	{
		hanoi(x, z, y, n - 1);
		cout << n << ":" << x << "→" << y << endl;
		hanoi(z, y, x, n - 1);
	}
}
int main()
{
	hanoi('A', 'B', 'C', 6);
	return 0;
}