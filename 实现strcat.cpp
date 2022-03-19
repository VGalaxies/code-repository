// µœ÷strcat
#include<iostream>
using namespace std;
unsigned int Strlen(const char* str)
{
	int count = 0;
	for (int i = 0; *str != '\0'; str++)
		count++;
	return count;
}
char* Strcat(char* dst, const char* src)
{
	int i = 0;
	int len = Strlen(dst);
	while (src[i] != '\0')
	{
		dst[len + i] = src[i];
		++i;
	}
	dst[len+i] = '\0';
	return dst;
}
int main()
{
	char a[10]="hi,";
	const char* b = "hello";
	Strcat(a, b);
	cout << a;
	return 0;
}