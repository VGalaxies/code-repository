#include<iostream>
#include<cstring>
using namespace std;
char a[63000];
void Tennis(char* a, int n)
{
	int len = strlen(a);
	int count = 0;
	int set = 0;//��¼���һ���ֵĴ���
	int countW = 0, countL = 0;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] == 'W' || a[i] == 'L')
			count++;
		if (a[i] == 'W')
			countW++;
		if (a[i] == 'L')
			countL++;
		if (count == n)
		{
			cout << countW << ":" << countL << endl;
			set++;
			count = 0;
			countW = 0;
			countL = 0;
			continue;
		}
		if (len - n * set < n && i == len - 1)
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