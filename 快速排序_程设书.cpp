#include<iostream>
using namespace std;
int a[100010];
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int spilt(int* a, int begin, int end)//寻找分治划分，难理解的一部分
{
	int spilt_point = begin;//下标
	int spilt = a[begin];//值
	for (int i = begin + 1; i <= end; ++i)
	{
		if (a[i] < spilt)
		{
			spilt_point++;
			swap(a[i], a[spilt_point]);
		}
	}
	swap(a[begin], a[spilt_point]);
	return spilt_point;//别忘了return返回
}
void quick_sort(int* a, int begin, int end)
{
	if (begin < end)//不写会报错
	{
		int spilt_point = spilt(a, begin, end);
		quick_sort(a, begin, spilt_point - 1);
		quick_sort(a, spilt_point + 1, end);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	quick_sort(a, 1, n);
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	return 0;
}