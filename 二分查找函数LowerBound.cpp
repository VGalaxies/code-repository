/*
дһ������LowerBound��
�ڰ���size��Ԫ�صġ���С���������int����a����ұȸ�������pС�ģ�
�±�����Ԫ�ء�
�ҵ��򷵻����±꣬�Ҳ����򷵻�-1
*/
#include<iostream>
using namespace std;
int LowerBound(int a[], int size, int p)
{
	int L = 0;
	int R = size - 1;
	int Pos = -1;//
	while (L <= R)
	{
		int mid = L + (R - L) / 2;
		if (a[mid] >= p)
		{
			R = mid - 1;
		}
		else
		{
			Pos = mid;//
			L = mid + 1;
		}
	}
	return Pos;
}
int main()
{
	int a[10] = { 1,3,4,5,6,8,123,424,1414,10000 };
	int b = LowerBound(a, 10, 466);
	cout << b;
	return 0;
}