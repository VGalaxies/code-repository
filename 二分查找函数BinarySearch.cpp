/*
дһ������BinarySeach��
�ڰ���size��Ԫ�صġ���С���������int����a�����Ԫ��p,
����ҵ����򷵻�Ԫ���±꣬
����Ҳ������򷵻�-1��
Ҫ���Ӷ�O(log(n))
*/
#include<iostream>
using namespace std;
int BinarySearch(int *a, int size, int p)
{
	int L = 0;
	int R = size - 1;
	while (L <= R)//ע��Ⱥţ�������ֻ��һ��Ԫ�ص�Ȼ����
	{
		int mid = L + (R - L) / 2;//��Ҫдmid = (L+R)/2����ֹ���
		if (a[mid] == p)//���ֲ��ң�ֻ��Ŀ��Ԫ�غ������м�Ԫ�ش�С���бȽϣ����������Ԫ�ز��ܣ���Ҫдforѭ��
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
	int a[10] = { 1,3,4,5,6,8,123,424,1414,10000 };
	int b = BinarySearch(a, 10, 123);
	cout << b;
	return 0;
}