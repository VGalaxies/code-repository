#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ori[200010];
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ori[i]);
	long long max = -2 * 10000000000;
	for (int i = 0; i < n; ++i) {
		long long int tmp = 0;
		for (int j = i; j < n; ++j) {
			tmp += ori[j];
			if (tmp > max)
				max = tmp;
		}
	}
	printf("%lld", max);
	return 0;
}