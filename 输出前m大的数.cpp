/*
����
��һ�а���һ������n����ʾ����Ĵ�С��n < 100000��
�ڶ��а���n����������ʾ�����Ԫ�أ�����֮����һ���ո�ֿ�
��ÿ�������ľ���ֵ������100000000��
�����а���һ������m��m < n��
���
�Ӵ�С���ǰm�������ÿ����һ�С�


���������������Ӷ� O(nlogn)
�÷��δ������Ӷ� O(n+mlogm)

˼·����ǰm��Ķ�Ū���������ұߣ�Ȼ��������ұ�m��Ԫ�����������
�ؼ���O(n)ʱ����ʵ�ְ�ǰm��Ķ�Ū���������ұ�

�������arrangeRight(k): ������(�������һ���֣�ǰk���
��Ū�����ұ�
��ν�ǰk��Ķ�Ū�����ұ�
1����key=a[0], ��keyŲ���ʵ�λ�ã�ʹ�ñ�keyС��Ԫ�ض���
key��ߣ���key���Ԫ�ض���key�ұߣ�����ʱ����ɣ�
2) ѡ�������ǰ������ٽ��� arrangeRight�������������ۣ�
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