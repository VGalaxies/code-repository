/*
��k=a[0], ��kŲ���ʵ�λ�ã�
ʹ�ñ�kС��Ԫ�ض���k���,
��k���Ԫ�ض���k�ұߣ�
��k��ȵģ���������k���ҳ��־��ɣ�O(n)ʱ����ɣ�
��k��ߵĲ��ֿ�������
��k�ұߵĲ��ֿ�������
*/
/*�ƶ���ʽ
һ��j�����ң��ҵ�һ���Ȼ�׼��������k��С������
Ȼ����i�������ҵ�һ����k�������Ȼ����н�����
ֱ��i��j������ʼ���δ���
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
	if (first >= last)//�߽��������Ӳ��ӵȺŶ�����ν
		return;
	int k = a[first];//spilt���ֵ����
	int i = first;
	int j = last;
	while (i != j)
	{
		while (k <= a[j] && i < j)//i<j����������ֹ����i>j
			j--;
		swap(a[i], a[j]);//a[j]��Ϊk��
		while (k >= a[i] && i < j)//ע��˴�Ϊa[i]
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