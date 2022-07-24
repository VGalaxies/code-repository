/*�鲢����
��ǰһ������
�Ѻ�һ������
������鲢��һ���µ��������飬Ȼ���ٿ�����ԭ���飬������ɡ�
*/
#include<iostream>
using namespace std;
//int ans = 0;//�������
void Merge(int a[], int s, int m, int e, int tmp[])
{
	int count = s;
	int p1 = s;
	int p2 = m + 1;
	while (p1 <= m && p2 <= e)//Ӧ��Ϊ&&����||������������������Ż��˳�ѭ��
	{
		if (a[p1] <= a[p2])
		{
			tmp[count] = a[p1];
			p1++;
			count++;
		}
		else
		{
			tmp[count] = a[p2];
			p2++;
			count++;
			//ans += m - p1 + 1;
		}
	}
	while (p1 <= m)
		tmp[count++] = a[p1++];//�򻯵ı��
	while (p2 <= e)
		tmp[count++] = a[p2++];
	for (int i = s; i <= e; ++i)
		a[i] = tmp[i];
	
}
void MergeSort(int a[], int s, int e, int tmp[])
{
	if (s < e) //s=e˵���������
	{
		int m = s + (e - s) / 2; 
		MergeSort(a, s, m, tmp); 
		MergeSort(a, m + 1, e, tmp);
		Merge(a, s, m, e, tmp);
	}
}
int a[6] = { 5,4,2,6,3,1 };
int b[6];
int main()
{
	int size = sizeof(a) / sizeof(int);
	MergeSort(a, 0, size - 1, b);
	for (int i = 0; i < size; ++i)
		cout << a[i] << " ";
	//cout << ans;
	return 0;
}