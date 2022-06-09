/*
ũ�� John ������һ���ܳ���������������N (2��N��100,000)�����䣬��
ЩС�����λ��Ϊx0,...,xN-1 (0��xi��1,000,000,000,��Ϊ����,������ͬ).
John��C (2��C��N)ͷţÿͷ�ֵ�һ�����䡣ţ��ϣ���������Զ��ʡ�û�����š�
��������ʹ������ͷţ֮�����С���뾡���ܵĴ����������С�����Ƕ����أ�

����
Line 1: Two space-separated integers: N and C
Lines 2..N+1: Line i+1 contains an integer stall location, xi
���
Line 1: One integer: the largest minimum distance

�ȵõ������ĸ������� x0,...,xN-1
��1,000,000,000/C��1���γ������������������롱D�� �ҵ���
��һ�����еľ��Ǵ𰸡�
���Է�����
1)	��1ͷţ����x0
2)	����kͷţ����xi �����ҵ�xi+1��xN-1�е�һ��λ��[xi+D, 1,000,000,000]�е�Xj
,��k+1ͷţ����Xj���Ҳ���������Xj,�� D=D-1,ת 1)����
������ţ���ܷ��£���D����
���Ӷ� 1,000,000,000/C *N���� 1,000,000,000, ��ʱ!

��[L,R]���ö��ַ����ԡ����������롱D = (L+R)/2 (L,R��ֵΪ
[1,	1,000,000,000/C]
��D���У����ס��D��Ȼ������[L,R]�м�������(L= D+1) ��D�����У�������[L,R]�м�������(R= D-1)
���Ӷ� log(1,000,000,000/C) * N
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int location[100010];//�±��ʾ���䣬ֵ��ʾ����λ��
int cow[100010];//��¼ÿͷţ���ڵĸ���λ��
int main()
{
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		cin >> location[i];
		cin.get();//��ȥ�س�
	}
	sort(location, location + N);
	int D = 1000000000 / C;//��ʼ��minimum distance
	int L = 0;
	int R = D;
	int mid = 0;
	int ans = 0;
	while (L <= R)
	{
		mid = (L + R) / 2;
		cow[0] = location[0];
		int count = 1;//�ж�ÿͷţ�Ƿ񶼷����˸�����
		int i = 0;//iΪţ���±�
		int j = 1;//jΪ�����±�
		while (count < C && j!=N )
		{
			while(j <= N - 1)
			{
				if (location[j] - cow[i] >= mid)
				{
					cow[i + 1] = location[j];
					i++;
					count++;
					break;
				}
				else
				{
					j++;
				}
			}
		}
		if (count == C)
		{
			L = mid+1;
			ans = R;
			memset(cow, 0, 100010 *sizeof(int));
		}
		else
		{
			R = mid-1;
			ans = R;
			memset(cow, 0, 100010 * sizeof(int));
		}
	}
	cout << ans;
	return 0;
}