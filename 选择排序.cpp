/*ѡ������
�����N��Ԫ����Ҫ����
��ô���ȴ�N��Ԫ�����ҵ���С���Ǹ�(��Ϊ��0С��)���ڵ�0��λ����(��ԭ���ĵ�0��λ���ϵ�Ԫ�ؽ���λ��)��
Ȼ���ٴ�ʣ�µ�N-1��Ԫ�����ҵ���С�ķ��ڵ�1��λ���ϣ�
Ȼ���ٴ�ʣ�µ�N-2��Ԫ�����ҵ���С�ķ��ڵ�2��λ���ϡ���ֱ�����е�Ԫ�ض���λ��
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
	int count = 1;
	while (count < n)
	{
		int i = count+1;
		int min_point = count;//�˴�Ϊ�±꣬�����ٶ���һ��min=a[count]��ȫ���࣡��
		for (i; i <= n; ++i)
			if (a[i] < a[min_point])
				min_point = i;//ֻ���±ֵ꣬����
		swap(a[count], a[min_point]);
		++count;
	}
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	return 0;
}