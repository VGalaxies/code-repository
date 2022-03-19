/*
����n ( n<= 100,000)���������ҳ����е�������������֮�͵�������m(�ٶ�
�϶��н�)�������������������� int ��ʾ

1)	���������򣬸��Ӷ���O(n��log(n))
2)	�������е�ÿ��Ԫ��a[i],�������ж��ֲ���m-a[i]�����ܷ��ҵ������Ӷ�log(n)���Ҫ����n-2�Σ����Բ����ⲿ�ֵĸ��Ӷ�Ҳ��O(n��log(n))
���ֽⷨ�ܵĸ��Ӷ���O(n��log(n))�ġ�

*/
#include<iostream>
#include<algorithm>
using namespace std;
int ori[100010];
int BinarySearch(int* a, int size, int p)
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
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < n; ++i)
		cin >> ori[i];
	sort(ori, ori + n);//C++�е�sort()������
	for (int i = 0; i < n; ++i)
	{
		int result = BinarySearch(ori, n, m - ori[i]);
		if (result != -1)
			cout << ori[i] <<" " <<ori[result]<<endl;
	}
	return 0;
}