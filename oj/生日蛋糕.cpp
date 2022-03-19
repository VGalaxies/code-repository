#include<iostream>
#include<cmath>
using namespace std;
int N, M, S;
int Q = 1 << 30;
int tmp_Q = 0;
int cubic(int n)
{
	return (n * n * (n + 1) * (n + 1) / 4);
}
int maxV(int r, int h, int m)
{
	int ans = 0;
	for (int i = m; i >= 1; --i)
	{
		ans += r * r * h;
		r--;
		h--;
	}
	return ans;
}
void Dfs(int v, int r, int h, int m)//最底层半径至多为r,高度至多为h,m层拼体积v
{
	if (m == 0)
	{
		if (v)
			return;
		else
		{
			Q = min(Q, tmp_Q);
			return;
		}
	}
	if (v <= 0)
		return;
	if (tmp_Q >= Q)//最优性剪枝
		return;
	if (v < cubic(m))//预见，可行性剪枝
		return;
	if (v > maxV(r, h, m))//预见，可行性剪枝
		return;
	for (int rr = r; rr >= m; --rr)
	{
		if (m == M)//底面积
			tmp_Q = rr * rr;
		for (int hh = h; hh >= m; --hh)
		{
			tmp_Q += 2 * rr * hh;
			Dfs(v - rr * rr * hh, rr - 1, hh - 1, m - 1);
			tmp_Q -= 2 * rr * hh;
		}
	}
}
int main()
{
	cin >> N >> M;
	int max_r = floor(sqrt(N));
	int max_h = (N - cubic(M - 1)) / M;
	Dfs(N, max_r, max_h, M);
	if (Q == 1 << 30)
		cout << 0;
	else
		cout << Q;
}