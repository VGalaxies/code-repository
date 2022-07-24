#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int n;
char ori[10010][110];
int MyCompare(const void* a, const void* b)
{
	char * p1, * p2;
	p1 = (char*)a;
	p2 = (char*)b;
	return strcmp(p1, p2);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ori[i];
	qsort(ori, n, sizeof(char), MyCompare);
	for (int i = 0; i < n; ++i)
		cout << ori[i] << " ";
}