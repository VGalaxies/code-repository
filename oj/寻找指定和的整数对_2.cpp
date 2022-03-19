/*
����n ( n<= 100,000)���������ҳ����е�������������֮�͵�������m(�ٶ�
�϶��н�)�������������������� int ��ʾ

1)	���������򣬸��Ӷ���O(n��log(n))
2)	���ҵ�ʱ��������������i��j,i��ֵ��0,j��ֵ��n-1.��a[i]+a[ j],�������m������j ��1�����С��m,����i��1��ֱ��a[i]+a[ j]=m��
���ֽⷨ�ܵĸ��Ӷ���O(n��log(n))��
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
	sort(ori, ori + n);//C++�е�sort()������
	int L = 0;
	int R = n - 1;
	while (L <= R)
	{
		if (ori[L] + ori[R] == m)
		{
			cout << ori[L] <<" "<< ori[R];
			break;//�������һ���
		}
		else if (ori[L] + ori[R] > m)
			R--;
		else
			L++;
	}
	return 0;
}
