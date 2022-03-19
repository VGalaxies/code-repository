/*
输入n ( n<= 100,000)个整数，找出其中的两个数，它们之和等于整数m(假定
肯定有解)。题中所有整数都能用 int 表示

1)	将数组排序，复杂度是O(n×log(n))
2)	对数组中的每个元素a[i],在数组中二分查找m-a[i]，看能否找到。复杂度log(n)，最坏要查找n-2次，所以查找这部分的复杂度也是O(n×log(n))
这种解法总的复杂度是O(n×log(n))的。

*/
#include<iostream>
#include<algorithm>
using namespace std;
int ori[100010];
int BinarySearch(int* a, int size, int p)
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
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < n; ++i)
		cin >> ori[i];
	sort(ori, ori + n);//C++中的sort()排序函数
	for (int i = 0; i < n; ++i)
	{
		int result = BinarySearch(ori, n, m - ori[i]);
		if (result != -1)
			cout << ori[i] <<" " <<ori[result]<<endl;
	}
	return 0;
}