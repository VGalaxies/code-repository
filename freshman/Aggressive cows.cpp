/*
农夫 John 建造了一座很长的畜栏，它包括N (2≤N≤100,000)个隔间，这
些小隔间的位置为x0,...,xN-1 (0≤xi≤1,000,000,000,均为整数,各不相同).
John的C (2≤C≤N)头牛每头分到一个隔间。牛都希望互相离得远点省得互相打扰。
怎样才能使任意两头牛之间的最小距离尽可能的大，这个最大的最小距离是多少呢？

输入
Line 1: Two space-separated integers: N and C
Lines 2..N+1: Line i+1 contains an integer stall location, xi
输出
Line 1: One integer: the largest minimum distance

先得到排序后的隔间坐标 x0,...,xN-1
从1,000,000,000/C到1依次尝试这个“最大的最近距离”D， 找到的
第一个可行的就是答案。
尝试方法：
1)	第1头牛放在x0
2)	若第k头牛放在xi ，则找到xi+1到xN-1中第一个位于[xi+D, 1,000,000,000]中的Xj
,第k+1头牛放在Xj。找不到这样的Xj,则 D=D-1,转 1)再试
若所有牛都能放下，则D即答案
复杂度 1,000,000,000/C *N，即 1,000,000,000, 超时!

在[L,R]内用二分法尝试“最大最近距离”D = (L+R)/2 (L,R初值为
[1,	1,000,000,000/C]
若D可行，则记住该D，然后在新[L,R]中继续尝试(L= D+1) 若D不可行，则在新[L,R]中继续尝试(R= D-1)
复杂度 log(1,000,000,000/C) * N
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int location[100010];//下标表示隔间，值表示隔间位置
int cow[100010];//记录每头牛所在的隔间位置
int main()
{
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		cin >> location[i];
		cin.get();//除去回车
	}
	sort(location, location + N);
	int D = 1000000000 / C;//初始的minimum distance
	int L = 0;
	int R = D;
	int mid = 0;
	int ans = 0;
	while (L <= R)
	{
		mid = (L + R) / 2;
		cow[0] = location[0];
		int count = 1;//判断每头牛是否都放入了隔间中
		int i = 0;//i为牛的下标
		int j = 1;//j为隔间下标
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