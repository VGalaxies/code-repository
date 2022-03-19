#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int t;
int MyStrcmp(const char* a, const char* b)
{
	int i = 0;
	while (a[i] == b[i] && a[i] != '\0' && b[i] != '\0')
		i++;
	if (a[i] < b[i])
		return -1;
	else if (a[i] > b[i])
		return 1;
	else
		return 0;
}
inline void swap(register char** a, register char** b) {
	char* tmp = *b;
	*b = *a;
	*a = tmp;
}
int main()
{
	scanf("%d", &t);
	while (t--){
		char ori[110][50];
		char* p[110];
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{scanf("%s", ori[i]); p[i] = ori[i];}
		for (int i = 0; i < n - 1; ++i)
			for (int j = n - 2; j >= 0; --j)
				if (MyStrcmp(p[j], p[j + 1]) > 0) {
					swap(&p[j], &p[j + 1]);
					/*char* tmp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = tmp;*/
				}
		printf("%s %s\n", p[0], p[n - 1]);
	}
}