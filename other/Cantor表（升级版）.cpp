#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int a1, a2, b1, b2;
int factor(int a, int b) {
	return (b == 0) ? a : factor(b, a % b);
}
int main() {
	scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
	int a = a1 * a2;
	int b = b1 * b2;
	int tmp = factor(a, b);
	a /= tmp;
	b /= tmp;
	printf("%d %d", b, a);
}