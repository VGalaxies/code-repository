/*选择排序
如果有N个元素需要排序，
那么首先从N个元素中找到最小的那个(称为第0小的)放在第0个位子上(和原来的第0个位子上的元素交换位置)，
然后再从剩下的N-1个元素中找到最小的放在第1个位子上，
然后再从剩下的N-2个元素中找到最小的放在第2个位子上……直到所有的元素都就位。
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
	int count = 1;
	while (count < n)
	{
		int i = count+1;
		int min_point = count;//此处为下标，不用再多设一个min=a[count]完全多余！！
		for (i; i <= n; ++i)
			if (a[i] < a[min_point])
				min_point = i;//只变下标，值不变
		swap(a[count], a[min_point]);
		++count;
	}
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	return 0;
}