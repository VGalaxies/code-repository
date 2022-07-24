#include<iostream>
#include<climits>
using namespace std;
int SV_1[23];
int SV_2[23];
int ST_1[23];
int ST_2[23];
int ways(int w, int h, int k)//ÇÐkµ¶
{
	if (w * h < k + 1)
		return INT_MIN;
	if (k == 0)
		return w * h;
	else 
	{
		int SV_min;//ÊúÇÐ
		int ST_min;//ºáÇÐ
		for (int i = 1; i <= w-1; ++i)
		{
			for (int j = 0; j <= k - 1; ++j)
			{
				int x = ways(i, h, j);
				int y = ways(w - 1 - i, h, k - 1 - j);
				SV_2[j] = max(x, y);
			}
			int min;
			for (int j = 0; j <= k - 1; ++j)
			{
				min = SV_2[0];
				if (SV_2[j] < min)
					min = SV_2[j];
			}
			SV_1[i] = min;
		}
		for (int i = 1; i <= w - 1; ++i)
		{
			SV_min = SV_1[1];
			if (SV_1[i] < SV_min)
				SV_min = SV_1[i];
		}
		memset(SV_1, 0, sizeof(SV_1));
		memset(SV_2, 0, sizeof(SV_2));

		for (int i = 1; i <= h - 1; ++i)
		{
			for (int j = 0; j <= k - 1; ++j)
			{
				int x = ways(w, i, j);
				int y = ways(w, h - 1 - i, k - 1 - j);
				ST_2[j] = max(x, y);
			}
			int min;
			for (int j = 0; j <= k - 1; ++j)
			{
				min = ST_2[0];
				if (ST_2[j] < min)
					min = ST_2[j];
			}
			ST_1[i] = min;
		}
		for (int i = 1; i <= h - 1; ++i)
		{
			SV_min = ST_1[1];
			if (ST_1[i] < SV_min)
				SV_min = ST_1[i];
		}
		memset(ST_1, 0, sizeof(ST_1));
		memset(ST_2, 0, sizeof(ST_2));
		return min(SV_min, ST_min);
	}
}
int main()
{
	int w, h, m;//·Ö³Ém¿é
	cin >> w >> h >> m;
	cout << ways(w, h, m - 1);
	return 0;
}