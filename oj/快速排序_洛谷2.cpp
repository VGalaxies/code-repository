/*�ƶ���ʽ
��׼������k����׼���±����x
�� i�������ҵ�һ����k�����,a[x]=a[i]��
�� j�����ң��ҵ�һ����kС����,a[i]=a[j]��
�� i�������ҵ�һ����k�����,a[j]=a[i]��
�� �ظ��ڢ�ֱ��i==j��
�� ��a[i]��ֵΪ��׼��k��
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
	int k = a[first];
	int i = first;
	int j = last;
	if (i >= j)//�߽�����
		return;
	while (i < j)
	{
		while (i < j && a[j] > k)
			j--;
		if (i < j)
		{
			a[i] = a[j];
			i++;
		}
		while (i < j && a[i] < k)
			i++;
		if (i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = k;
	quick_sort(a, first,i - 1);
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