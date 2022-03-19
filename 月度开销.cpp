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
		cin.get();//除去回车
	}
	int L = max;//预处理，最小开销至少跟花费最大的那个月一样
	int R = sum;//最大开销可能是所有的月加起来
	int mid;

	while (L < R)
	{
		int mid = (L + R) / 2;
		int tmp_sum = 0;//累积当前的钱
		int count = 0;//分成几组
		for(int i=0;i<N;++i)
		{
			if (tmp_sum +ori[i] <= mid)//如果加上这个月的花费还比枚举到的开销小
				tmp_sum += ori[i];//那就继续加
			else//不然就要分一组出来
			{
				tmp_sum = ori[i];
				count++;
			}
		}
		if (count >= M)//注意有等号
		{
			L = mid + 1;//可分的组数较多，说明开销还可以更大
			ans = L;
		}
		else
		{
			R = mid - 1;//开销太大导致分的组数少
			ans = L;
		}	
	}
	cout << ans;
	return 0;
}