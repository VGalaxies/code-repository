#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char a[63000];
void Tennis(char* a, int n)
{
	int len = strlen(a);
	int count = 0;
	int countW = 0, countL = 0;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] == 'W')
		{
			countW++;
			count++;
		}
		if (a[i] == 'L')
		{
			countL++;
			count++;
		}
		if (count == n)
		{
			if(abs(countW-countL)>=2)
				cout << countW << ":" << countL << endl;
			else
			{
				for (int j = i+i; j < len; ++j)
				{
					if (a[i] == 'W')
					{
						countW++;
					}
					if (a[i] == 'L')
					{
						countL++;
					}
					if ((abs(countW - countL) >= 2))
					{
						cout << countW << ":" << countL << endl;
						break;
					}
						
				}
			}
			count = 0;
			countW = 0;
			countL = 0;
			continue;
		}
		if (len - i < n && i == len - 1)
		{
			cout << countW << ":" << countL << endl;
			break;
		}
	}
}
int main()
{
	cin.get(a, 63000, 'E');
	Tennis(a, 11);
	cout << endl;
	Tennis(a, 21);
	return 0;
}