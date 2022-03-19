#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void test(int x, int y, int z) {
	int a = x;
	int b = y;
	int c = z;
	printf("%d %p\n", x, &x);
	printf("%d %p\n", y, &y);
	printf("%d %p\n", z, &z);
	printf("%d %p\n", a, &a);
	printf("%d %p\n", b, &b);
	printf("%d %p\n", c, &c);
}
int main() {
	test(1, 2, 3);
}