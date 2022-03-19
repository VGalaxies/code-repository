/*
设k=a[0], 将k挪到适当位置，
使得比k小的元素都在k左边,
比k大的元素都在k右边，
和k相等的，不关心在k左右出现均可（O(n)时间完成）
把k左边的部分快速排序
把k右边的部分快速排序
*/
/*移动方式
一是j（从右）找到一个比基准数（记作k）小的数，
然后让i（从左）找到一个比k大的数，然后进行交换。
直到i，j相遇开始分治处理；
*/
#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quick_sort(int* a, int first, int last)
{
	if (first >= last)//边界条件，加不加等号都无所谓
		return;
	int k = a[first];//spilt点的值不变
	int i = first;
	int j = last;
	while (i != j)
	{
		while (k <= a[j] && i < j)//i<j不可忘，防止出现i>j
			j--;
		swap(a[i], a[j]);//a[j]变为k了
		while (k >= a[i] && i < j)//注意此处为a[i]
			i++;
		swap(a[i], a[j]);
	}
	quick_sort(a, first, i - 1);
	quick_sort(a, i+1, last);
}
int a[] = { 93,27,30,2,8,12,2,8,30,89 };
int main()
{
	int size = sizeof(a) / sizeof(int);
	quick_sort(a, 0, size - 1);
	for (int i = 0; i < size; ++i) 
		cout << a[i] << " ";
	cout << endl;
	return 0;
}