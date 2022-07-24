#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ori[200010];
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ori[i]);
	long long int max = ori[0];
	long long int now = ori[0];
	for (int i = 1; i < n; ++i) {
		now += ori[i];
		if (now < 0)
			now = 0;
		if (now > max)
			max = now;
	}
	printf("%lld", max);
	return 0;
}