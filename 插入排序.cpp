/*��������
����������a��Ϊ����Ĳ��ֺ�������������֡�ǰ������ߣ��������ұߡ�
��ʼ����Ĳ���ֻ��a[0]�����඼��������Ĳ���
ÿ��ȡ�����򲿷ֵĵ�һ��������ߣ�Ԫ�أ��������뵽���򲿷֡�������뵽����λ��p, ��ԭpλ�ü����������򲿷�Ԫ�أ��������ƶ�һ��λ�ӡ�����Ĳ��ּ�������һ��Ԫ�ء�
ֱ������Ĳ���û��Ԫ��
*/
#include<iostream>
using namespace std;
int a[10000];
void swap(int* a, int* b)//������������ֵ
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
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (a[i] < a[j])
			{
				for (int k = i; k >= j+1; --k)
					swap(a[k], a[k - 1]);//��ͦ�����
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << a[i]<<" ";
	return 0;
}
