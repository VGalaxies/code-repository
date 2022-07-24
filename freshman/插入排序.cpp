/*插入排序
将整个数组a分为有序的部分和无序的两个部分。前者在左边，后者在右边。
开始有序的部分只有a[0]，其余都属于无序的部分
每次取出无序部分的第一个（最左边）元素，把它加入到有序部分。假设插入到合适位置p, 则原p位置及其后面的有序部分元素，都向右移动一个位子。有序的部分即增加了一个元素。
直到无序的部分没有元素
*/
#include<iostream>
using namespace std;
int a[10000];
void swap(int* a, int* b)//交换两个变量值
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (a[i] < a[j])
			{
				for (int k = i; k >= j+1; --k)
					swap(a[k], a[k - 1]);//就挺巧妙的
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << a[i]<<" ";
	return 0;
}
