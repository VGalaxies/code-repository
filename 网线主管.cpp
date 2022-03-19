#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double wire[10010];
int n, k;
long long unsigned int totalLen;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &wire[i]);
		wire[i] *= 100;
		totalLen += int(wire[i]);
	}
	long long unsigned int initial_len = int(totalLen / k);
	
	long long unsigned int R = initial_len;
	long long unsigned int L = 0;
	long long unsigned int mid = L + (R - L) / 2;
	long long unsigned int ans = 0;
	while (L <= R) {
		mid = L + (R - L) / 2;
		int autual_k = 0;
		for (int i = 0; i < n; ++i)
			autual_k += int(wire[i] / mid);
		if (autual_k >= k)
			L = mid + 1;
		else
			R = mid - 1;
	}
	printf("%.2f", R * 0.01);
}