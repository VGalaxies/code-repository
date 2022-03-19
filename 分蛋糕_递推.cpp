#include<iostream>
#include<climits>
#include<cstring>
#include<cmath>
using namespace std;
int ways[23][23][23];
int SV_1[23];
int SV_2[23];
int ST_1[23];
int ST_2[23];
int main()
{
	int w, h, m;
	cin >> w >> h >> m;
	for (int i = 1; i <= w; ++i)
		for (int j = 1; j <= h; ++j)
			ways[i][j][0] = i * j;
	for (int i = 1; i <= w; ++i)
		for (int j = 1; j <= h; ++j)
			for (int k = 1; k <= m - 1; ++k)
				if (i * j < k + 1)
					ways[i][j][k] = INT_MIN;//
	for (int j = 1; j <= h; ++j)//考虑长为1
		for (int k = 1; k <= m - 1; ++k)
			if(j >= k + 1)
				ways[1][j][k] = ceil(j * 1.0 / (k + 1));
	for (int i = 1; i <= w; ++i)//考虑宽为1
		for (int k = 1; k <= m - 1; ++k)
			if (i >= k + 1)
				ways[i][1][k] = ceil(i * 1.0 / (k + 1));
	for (int i = 2; i <= w; ++i)//考虑长大于1，第一刀竖切
	{
		for (int j = 1; j <= h; ++j)
		{
			for (int k = 1; k <= m - 1; ++k)
			{
				for (int p = 1; p <= i - 1; ++p)
				{
					for (int q = 0; q <= k-1; ++q)
					{
						int x = ways[p][j][q];
						int y = ways[i - 1 - p][j][k - 1 - q];
						SV_2[q] = max(x, y);
					}
					int min;
					for (int q = 0; q <= k - 1; ++q)
					{
						min = SV_2[0];
						if (SV_2[q] < min)
							min = SV_2[q];
					}
					SV_1[p] = min;
				}
				int min;
				for (int p = 1; p <= i - 1; ++p)
				{
					min = SV_1[1];
					if (SV_1[p] < min)
						min = SV_1[p];
				}
				ways[i][j][k] = min;
				memset(SV_1, 0, sizeof(SV_1));
				memset(SV_2, 0, sizeof(SV_2));
			}
		}
	}
	for (int i = 1; i <= w; ++i)//考虑宽大于1，第一刀横切
	{
		for (int j = 2; j <= h; ++j)
		{
			for (int k = 1; k <= m - 1; ++k)
			{
				for (int p = 1; p <= j - 1; ++p)
				{
					for (int q = 0; q <= k - 1; ++q)
					{
						int x = ways[i][p][q];
						int y = ways[i][j - 1 - p][k - 1 - q];
						ST_2[q] = max(x, y);
					}
					int min;
					for (int q = 0; q <= k - 1; ++q)
					{
						min = ST_2[0];
						if (ST_2[q] < min)
							min = ST_2[q];
					}
					ST_1[p] = min;
				}
				int min;
				for (int p = 1; p <= j - 1; ++p)
				{
					min = ST_1[1];
					if (ST_1[p] < min)
						min = ST_1[p];
				}
				if (min < ways[i][j][k])
					ways[i][j][k] = min;
				memset(ST_1, 0, sizeof(ST_1));
				memset(ST_2, 0, sizeof(ST_2));
			}
		}
	}
	cout << ways[w][h][m - 1];
	return 0;
}