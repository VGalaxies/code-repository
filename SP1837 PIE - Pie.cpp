/*
描述
我的生日要到了！根据习俗，我需要将一些派分给大家。
我有N个不同口味、不同大小的派。有F个朋友会来参加我的派对，每个人会拿到一块派
（必须一个派的一块，不能由几个派的小块拼成；可以是一整个派）。

我的朋友们都特别小气，如果有人拿到更大的一块，就会开始抱怨。
因此所有人拿到的派是同样大小的（但不需要是同样形状的），
虽然这样有些派会被浪费，但总比搞砸整个派对好。
当然，我也要给自己留一块，而这一块也要和其他人的同样大小。

请问我们每个人拿到的派最大是多少？每个派都是一个高为1，半径不等的圆柱体。

输入
第一行包含两个正整数N和F，1 ≤ N, F ≤ 10 000，表示派的数量和朋友的数量。
第二行包含N个1到10000之间的整数，表示每个派的半径。

输出
输出每个人能得到的最大的派的体积，精确到小数点后三位。

*/
#include<iostream>
#include<iomanip>
using namespace std;
double pie[10010];//每个派的半径
const double pi = 3.14159265358979323846;
int N, F;
int V(double x)   //计算能分到的人数 
{
	int ans = 0;
	for (register int i = 0; i < N; i++) {
		ans += (int)(pie[i] / x);
	}
	return ans;
}
int main()
{
	
	cin >> N >> F;
	double max = 0;
	for (int i = 0; i < N; ++i)
		cin >> pie[i];
	for (int i = 0; i < N; ++i)//半径平方
	{
		pie[i] = pie[i] * pie[i] * pi;
		if (pie[i] > max)
			max = pie[i];
	}
	double L = 0;
	double R = max;
	double mid;
	while (R-L>0.00001)//精度高一点
	{
		mid = (L + R) / 2;
		if (V(mid) >= F+1)
			L = mid;
		else
			R = mid;
	}
	cout << setiosflags(ios::fixed) << setprecision(3) << mid << endl;
	return 0;
}