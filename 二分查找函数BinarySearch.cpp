/*
写一个函数BinarySeach，
在包含size个元素的、从小到大排序的int数组a里查找元素p,
如果找到，则返回元素下标，
如果找不到，则返回-1。
要求复杂度O(log(n))
*/
#include<iostream>
using namespace std;
int BinarySearch(int *a, int size, int p)
{
	int L = 0;
	int R = size - 1;
	while (L <= R)//注意等号，区间中只有一个元素当然可以
	{
		int mid = L + (R - L) / 2;//不要写mid = (L+R)/2，防止溢出
		if (a[mid] == p)//二分查找，只对目标元素和区间中间元素大小进行比较，区间的其他元素不管，不要写for循环
			return mid;
		else if (a[mid] > p)
			R = mid - 1;
		else
			L = mid + 1;
	}
	return -1;
}
int main()
{
	int a[10] = { 1,3,4,5,6,8,123,424,1414,10000 };
	int b = BinarySearch(a, 10, 123);
	cout << b;
	return 0;
}