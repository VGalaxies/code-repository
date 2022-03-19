#include<iostream>
#include<cstring>
using namespace std;
int a[105][105];
int b[105][105];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char tmp;
			cin >> tmp;
			if (tmp == '*')
			{
				a[i][j] = 1;
				b[i][j] = a[i][j];
			}
			else
			{
				a[i][j] = 0;
				b[i][j] = a[i][j];
			}
			
		}
	}
	for (int i = 0,j=0; j <= m + 1; ++j)
		a[i][j] == 0;
	for (int i = n+1, j = 0; j <= m + 1; ++j)
		a[i][j] == 0;
	for (int i = 1, j = 0; i <= n; ++i)
		a[i][j] == 0;
	for (int i = 1, j = m+1; j <= n; ++j)
		a[i][j] == 0;
/*-------------------------------------------*/
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{


		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] == 1)
				cout << "*" ;
			else
			{
				int count = 0;//¼ÇÂ¼µØÀ×Êý
					for (int I = i - 1; I <= i + 1; ++I)
						for (int J = j - 1; J <= j + 1; ++J)
							if (a[I][J] == 1)
								count++;
					b[i][j] = count;
					cout << b[i][j] ;
					count = 0;
			}
		}
		cout << endl;
	}
	return 0;
}