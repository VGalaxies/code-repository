#include<iostream>
using namespace std;
int ori[100100];
int ans;
int main()
{
	int N, M;
	cin >> N >> M;
	int sum = 0;
	int max = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> ori[i];
		sum += ori[i];
		if (ori[i] > max)
			max = ori[i];
		cin.get();//��ȥ�س�
	}
	int L = max;//Ԥ������С�������ٸ����������Ǹ���һ��
	int R = sum;//��������������е��¼�����
	int mid;

	while (L < R)
	{
		int mid = (L + R) / 2;
		int tmp_sum = 0;//�ۻ���ǰ��Ǯ
		int count = 0;//�ֳɼ���
		for(int i=0;i<N;++i)
		{
			if (tmp_sum +ori[i] <= mid)//�����������µĻ��ѻ���ö�ٵ��Ŀ���С
				tmp_sum += ori[i];//�Ǿͼ�����
			else//��Ȼ��Ҫ��һ�����
			{
				tmp_sum = ori[i];
				count++;
			}
		}
		if (count >= M)//ע���еȺ�
		{
			L = mid + 1;//�ɷֵ������϶࣬˵�����������Ը���
			ans = L;
		}
		else
		{
			R = mid - 1;//����̫���·ֵ�������
			ans = L;
		}	
	}
	cout << ans;
	return 0;
}