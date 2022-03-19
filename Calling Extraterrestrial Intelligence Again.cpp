#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct {
	int a;
	int b;
}res[2020];
int m[2020];
int a[2020];
int b[2020];
int prime[10000];
int main() {
	int prime_index = 0;
	for (int i = 2; i <= 50000; ++i) {
		bool judge = true;
		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0)
				judge = false;
		if (judge)
			prime[prime_index++] = i;
	}
	int index = 0;
	int tmp_m, tmp_a, tmp_b;
	scanf("%d%d%d", &tmp_m, &tmp_a, &tmp_b);
	while (tmp_m != 0 && tmp_a != 0 && tmp_b != 0) {
		m[index] = tmp_m;
		a[index] = tmp_a;
		b[index] = tmp_b;
		index++;
		scanf("%d%d%d", &tmp_m, &tmp_a, &tmp_b);
	}
	for (int k = 0; k < index; ++k) {
		tmp_m = m[k];
		tmp_a = a[k];
		tmp_b = b[k];
		int tmp_max = 0;
		for (int i = 0; i < 65; ++i) {//前65个质数的平方小于100000
			int p = prime[i];
			int upper = floor(p * double(tmp_b) / double(tmp_a));
			for (int j = i; prime[j] <= upper; ++j) {
				int q = prime[j];
				if (tmp_a * q <= tmp_b * p && p * q <= tmp_m) {
					if (p * q > tmp_max) {
						res[k].a = p;
						res[k].b = q;
						tmp_max = p * q;
					}
				}
			}
		}
	}
	for (int i = 0; i < index; ++i) {
		printf("%d %d\n", res[i].a, res[i].b);
	}
}