/*
递归
分类写递推式（有盘子为空，就可以不用管空盘子了）
设i个苹果放在k个盘子里放法总数是 f(i,k)，则：
k > i 时，	
f(i,k) = f(i,i)
k <= i 时，总放法 = 有盘子为空的放法+没盘子为空的放法
f(i,k) = f(i,k-1) + f(i-k,k)
边界条件！！！
*/
#include<iostream>
using namespace std;
#include <iostream>
using namespace std;
int f(int m, int n) //m为苹果数，n为盘子数
{
	if (n > m)
		return f(m, m);
	if (m == 0)
		return 1;//不放苹果视为一种方法（因为之前在没有空盘子的情况中吗，已经给每个盘子放了一个苹果）
	if (n <= 0)
		return 0;//没有盘子可以放苹果，没有方法可以做到
	return f(m, n-1) + f(m-n, n);
}
int main() 
{
	int t, m, n;
	cin >> t;
	while (t--)
		cin >> m >> n;
	cout << f(m, n) << endl;
	return 0;
}