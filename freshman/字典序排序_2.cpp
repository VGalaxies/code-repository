#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
char* ori[100];//Ö¸ÕëÊý×é
int n;
int MyCompare(const void* a, const void* b)
{
	char** p1 = (char**)a;
	char** p2 = (char**)b;
	return strcmp(*p1, *p2);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char tmp[100];
		cin >> tmp;
		ori[i] = new char[strlen(tmp) + 1];
		strcpy(ori[i], tmp);
	}
	qsort(ori, n, sizeof(char*), MyCompare);
	for (int i = 0; i < n; ++i)
	{
		cout << *ori[i] << " ";
		delete[] ori[i];
	}
	return 0;
}