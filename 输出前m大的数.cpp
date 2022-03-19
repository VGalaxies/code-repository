/*
输入
第一行包含一个整数n，表示数组的大小。n < 100000。
第二行包含n个整数，表示数组的元素，整数之间以一个空格分开
。每个整数的绝对值不超过100000000。
第三行包含一个整数m。m < n。
输出
从大到小输出前m大的数，每个数一行。


排序后再输出，复杂度 O(nlogn)
用分治处理：复杂度 O(n+mlogm)

思路：把前m大的都弄到数组最右边，然后对这最右边m个元素排序，再输出
关键：O(n)时间内实现把前m大的都弄到数组最右边

引入操作arrangeRight(k): 把数组(或数组的一部分）前k大的
都弄到最右边
如何将前k大的都弄到最右边
1）设key=a[0], 将key挪到适当位置，使得比key小的元素都在
key左边，比key大的元素都在key右边（线性时间完成）
2) 选择数组的前部或后部再进行 arrangeRight操作（分类讨论）
*/
#include<iostream>
#include<algorithm>
using namespace std;
int ori[200010];
void myswap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void arrangeRight(int *a,int begin,int last,int k)
{
	int key = a[begin];
	int i = begin;
	int j = last;
	while (i != j)
	{
		while (a[j] > key && i < j)
			j--;
		myswap(a[i], a[j]);
		while (a[i] < key && i < j)
			i++;
		myswap(a[i], a[j]);
	}
	if (last - i + 1 == k)
		return;
	else if (last - i + 1 > k)
		arrangeRight(a, i + 1, last, k);
	else
		arrangeRight(a, begin, i - 1, k - (last - i + 1));
}
bool compare(int a, int b)
{
	return a > b; 
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ori[i];
	int k;
	cin >> k;
	arrangeRight(ori, 0, n - 1, k);
	int* p = ori;
	p += n - k;
	sort(p, p + k, compare);
	for (int i = n - k; i < n; ++i)
		cout << ori[i] << endl;
	return 0;
}