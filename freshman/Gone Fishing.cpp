#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n;
int h;
struct lake
{
	int f;
	int d;
	int id;
}ori[30];
struct fish
{
	int id;
	int t;
	int quantity;
	fish(int a, int b, int c) :id(a), t(b), quantity(c) {}
	bool operator<(const fish& a)const {
		if (a.quantity == quantity)
			return id > a.id;
		else
			return quantity < a.quantity;//���ȶ��еĶ���
	}
};
int gap[30];
int gap_trans[30];
struct result
{
	int quantity;
	int id[200];
}result[30];
int result_time[30];
int main()
{
	while (cin >> n >> h && n != 0)
	{
		memset(ori, 0, sizeof(ori));
		memset(gap, 0, sizeof(gap));
		memset(gap_trans, 0, sizeof(gap_trans));
		memset(result, 0, sizeof(result));
		memset(result_time, 0, sizeof(result_time));
		for (int i = 1; i <= n; ++i)
			cin >> ori[i].f;
		for (int i = 1; i <= n; ++i)
			cin >> ori[i].d;
		for (int i = 1; i <= n; ++i)
			ori[i].id = i;
		for (int i = 1; i <= n - 1; ++i)
			cin >> gap[i];
		gap_trans[0] = 0;
		for (int i = 1; i <= n - 1; ++i)
			gap_trans[i] = gap_trans[i - 1] + gap[i];
		for (int i = 1; i <= n; ++i)//���ͣ�ڵ�i����
		{
			int h_tmp = h * 12 - gap_trans[i - 1];
			priority_queue<fish> q;
			for (int j = 1; j <= i; ++j)//��j����
			{
				for (int k = 1; k <= h_tmp; ++k)//��k��ʱ��Ƭ
				{
					int num = ori[j].f - (k - 1) * ori[j].d;
					if (num < 0) num = 0;
					q.push(fish(j, k, num));
				}
			}
			for (int j = 1; j <= h_tmp; ++j)//��ǰh_tmp��quantity����
			{
				fish tmp = q.top();
				result[i].quantity += tmp.quantity;
				result[i].id[j] = tmp.id;
				q.pop();
			}
			while (!q.empty())//��ն���
				q.pop();
		}
		int max = result[1].quantity;
		int max_index = 1;//���ͣ�ڵ�max_index����
		for (int i = 1; i <= n; ++i)
		{
			if (result[i].quantity > max)
			{
				max = result[i].quantity;
				max_index = i;
			}
		}
		int max_h = h * 12 - gap_trans[max_index - 1];//���ͣ�ڵ�max_index�������ڵ����ʱ��
		for (int i = 1; i <= max_h; ++i)
			result_time[result[max_index].id[i]]++;//
		for (int i = 1; i <= n; ++i)
		{
			if (i == n)
				cout << result_time[i] * 5;
			else
				cout << result_time[i] * 5 << ", ";
		}
		cout << endl;
		cout << "Number of fish expected: "<< max << endl;
		cout << endl;
	}
	return 0;
}