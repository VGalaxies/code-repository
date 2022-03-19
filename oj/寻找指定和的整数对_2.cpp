/*
输入n ( n<= 100,000)个整数，找出其中的两个数，它们之和等于整数m(假定
肯定有解)。题中所有整数都能用 int 表示

1)	将数组排序，复杂度是O(n×log(n))
2)	查找的时候，设置两个变量i和j,i初值是0,j初值是n-1.看a[i]+a[ j],如果大于m，就让j 减1，如果小于m,就让i加1，直至a[i]+a[ j]=m。
这种解法总的复杂度是O(n×log(n))的
*/
#include<iostream>
#include<algorithm>
using namespace std;
int ori[100010];
int BinarySearch(int* a, int size, int p)
{
	int L = 0;
	int R = size - 1;
	while (L <= R)
	{
		int mid = L + (R - L) / 2;
		if (a[mid] == p)
			return mid;
		else if (a[mid] < p)
			R = mid - 1;
		else
			L = mid + 1;
	}
	return -1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> ori[i];
	sort(ori, ori + n);//C++中的sort()排序函数
	int L = 0;
	int R = n - 1;
	while (L <= R)
	{
		if (ori[L] + ori[R] == m)
		{
			cout << ori[L] <<" "<< ori[R];
			break;//假设仅有一组解
		}
		else if (ori[L] + ori[R] > m)
			R--;
		else
			L++;
	}
	return 0;
}
