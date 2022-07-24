#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100];
int Num(int* a, int L, int R)
{
	int ans = 0;
	for (int i = L; i <= R; ++i)
		ans = ans * 10 + a[i];
	return ans;
}
int V(int m, int n)
{
	if (m == 0)
		return Num(a, 0, n - 1);
	else
	{
		int min = Num(a, 0, n - 1);
		for (int i = m; i <= n - 1; ++i)
		{
			int tmp = V(m - 1, i) + Num(a, i, n - 1);
			if (tmp < min)
				min = tmp;
		}
		return min;
	}
}
int main()
{
	int m, n, i;
	while (cin >> m >> n) {
		i = 0;
		memset(a, 0, sizeof(a));
		while (n != 0) {
			a[i++] = n % 10;
			n /= 10;
		}
		reverse(a, a + i);
		cout << V(m, i) << endl;
	}
	return 0;
}