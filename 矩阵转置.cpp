#include <iostream>
using namespace std;
int a[105][105];
int b[105][105];
int main()
{
	int n, m;
	cin >> n >> m;//n––m¡–
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			b[i][j] = a[j][i];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << b[i][j] << " " ;
			if (j == n-1)
				cout << endl;
		}
	}
	return 0;
}